#include <fstream>
#include <cmath>

using namespace std;

double shortest_l(double* a, double* b, double* p) {
	double a_dis, b_dis;
	a_dis = (a[0] - p[0]) * (a[0] - p[0]) + (a[1] - p[1]) * (a[1] - p[1]) + (a[2] - p[2]) * (a[2] - p[2]);
	b_dis = (b[0] - p[0]) * (b[0] - p[0]) + (b[1] - p[1]) * (b[1] - p[1]) + (b[2] - p[2]) * (b[2] - p[2]);
    if(abs(a[0] - b[0]) < 0.00005 && abs(a[1] - b[1]) < 0.00005 && abs(a[2] - b[2]) < 0.00005)
        return a_dis;

    double mid[3];
	for (int i = 0; i < 3; i++) mid[i] = (a[i] + b[i]) / 2;

    if(a_dis < b_dis) return shortest_l(a, mid, p);
    else return shortest_l(mid, b, p);
}

double divide(double* a, double* b, double* c, double* d){
    double c_dis = shortest_l(a, b, c);
    double d_dis = shortest_l(a, b, d);
    if(abs(c[0] - d[0]) < 0.00005 && abs(c[1] - d[1]) < 0.00005 && abs(c[2] - d[2]) < 0.00005)
        return c_dis;

    double cd_mid[3];
    for(int i=0; i<3; i++) cd_mid[i] = (c[i]+d[i])/2;

    if (c_dis < d_dis) return divide(a, b, c, cd_mid);
    else return divide(a, b, cd_mid, d);
}

int main() {
    ifstream in("station.inp");
    ofstream out("station.out");
    double len;

	double a[3], b[3], c[3], d[3];
	in >> a[0] >> a[1] >> a[2];
	in >> b[0] >> b[1] >> b[2];
	in >> c[0] >> c[1] >> c[2];
	in >> d[0] >> d[1] >> d[2];
	in.close();

	len = divide(a, b, c, d);
	if (abs(sqrt(len)- round(sqrt(len))) < 0.005) {
        out<<(int)sqrt(len)<<endl;
        out.close();
        return 0;
	}
    out<<(int)ceil(sqrt(len))<<endl;
	out.close();
}
