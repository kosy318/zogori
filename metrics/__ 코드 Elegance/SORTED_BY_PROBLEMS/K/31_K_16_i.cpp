#include<bits/stdc++.h>

using namespace std;

struct vec {
	long long x, y, z;
	vec(long long x, long long y, long long z):x(x), y(y) ,z(z) {}

	vec operator -(const vec& other) const {
		return vec(x-other.x, y-other.y, z-other.z);
	}

	long long operator *(const vec& other) const {
		return x*other.x + y*other.y + z*other.z;
	}
};

inline vec outer(const vec& v1, const vec& v2) {
	return vec(v1.y*v2.z-v1.z*v2.y, v1.z*v2.x-v1.x*v2.z, v1.x*v2.y-v1.y*v2.x);
}

int n, kk;
vector<vec> v;

int dir[8][3] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1,}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};

int main() {
	scanf("%d %d", &n, &kk);
	for(int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		v.push_back(vec(x, y, z));
	}

	int sr1 = 0, sg1 = 0, sb1 = 0;
	for(int i = 0; i < n; i++) {
		sr1 += v[i].x*v[i].x, sg1 += v[i].y*v[i].y, sb1 += v[i].z*v[i].z;
	}

	double ret = (double)(sr1 + sg1 + sb1);
	int r1 = 0, g1 = 0, b1 = 0;
	for(int i = 0; i < n; i++) {
		r1 += v[i].x, g1 += v[i].y, b1 += v[i].z;
	}
	ret -= (double)((r1*r1)+(g1*g1)+(b1*b1))/n;

	if(kk == 2) {
		if(n <= 1)
			ret = 0;

		int sz[2] = {0, };
		int r[2] = {0, }, g[2] = {0, }, b[2] = {0, };
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				for(int k = j+1; k < n; k++) {
					vec nn = outer((v[j]-v[i]), (v[k]-v[i]));
					long long d = nn*v[i];

					sz[0] = sz[1] = 0;
					r[0] = r[1] = g[0] = g[1] = b[0] = b[1] = 0;
					for(int w = 0; w < n; w++) {
						if(i == w || j == w || k == w)	continue;

						int idx = 0;
						if(v[w]*nn > d) {
							idx = 1;
						}

						r[idx] += v[w].x;
						g[idx] += v[w].y;
						b[idx] += v[w].z;
						sz[idx]++;
					}

					for(int w = 0; w < 8; w++) {
						int idx = dir[w][0];
						r[idx] += v[i].x, g[idx] += v[i].y, b[idx] += v[i].z;
						sz[idx]++;
						idx = dir[w][1];
						r[idx] += v[j].x, g[idx] += v[j].y, b[idx] += v[j].z;
						sz[idx]++;
						idx = dir[w][2];
						r[idx] += v[k].x, g[idx] += v[k].y, b[idx] += v[k].z;
						sz[idx]++;

						double cur = (double)(sr1)+(sg1)+(sb1);
						for(int z = 0; z < 2; z++)
							if(sz[z] != 0)
								cur -= (double)(r[z]*r[z]+g[z]*g[z]+b[z]*b[z]) / sz[z];
						ret = min(ret, cur);
						idx = dir[w][0];
						r[idx] -= v[i].x, g[idx] -= v[i].y, b[idx] -= v[i].z;
						sz[idx]--;
						idx = dir[w][1];
						r[idx] -= v[j].x, g[idx] -= v[j].y, b[idx] -= v[j].z;
						sz[idx]--;
						idx = dir[w][2];
						r[idx] -= v[k].x, g[idx] -= v[k].y, b[idx] -= v[k].z;
						sz[idx]--;
					}
				}
	}

	printf("%.6lf\n", ret);
	return 0;
}
