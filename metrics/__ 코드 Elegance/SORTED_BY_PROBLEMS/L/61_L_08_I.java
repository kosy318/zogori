import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class L2 {
	static int n, m;
	static int[] v;
	static Min[] min;
	static int[][] memo;
	static int[] ei;

	public static void main(String[] args) throws IOException {
		input();
		solve();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		v = new int[n];
		for (int i = 0; i < n; i++) {
			v[i] = Integer.parseInt(br.readLine());
		}
		min = new Min[m];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			min[i] = new Min(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
					v[Integer.parseInt(st.nextToken()) - 1]);
		}
	}

	static void solve() {
		Arrays.sort(min);
		memo = new int[min[m - 1].e + 1][m];
		ei = new int[min[m - 1].e + 1];
		int index = -1;
		for (int i = 0; i <= min[m - 1].e; i++) {
			while (index + 1 < m) {
				if (min[index + 1].e < i) {
					index++;
				} else {
					break;
				}
			}
			ei[i] = index;
		}
		System.out.print(dp(min[m - 1].e, m - 1));
	}

	static int dp(int e, int index) {
		if (index < 0 || e <= 0) {
			return 0;
		}
		if (memo[e][index] > 0) {
			return memo[e][index];
		}
		return memo[e][index] = Math.max(dp(e, index - 1), dp((min[index].s), ei[min[index].s]) + min[index].v);
	}
}

class Min implements Comparable<Min> {
	int s, e, v;

	Min(int s, int e, int v) {
		this.s = s;
		this.e = e;
		this.v = (e - s) * v;
	}

	@Override
	public int compareTo(Min o) {
		if (this.e > o.e) {
			return 1;
		} else if (this.e == o.e) {
			return 0;
		}
		return -1;
	}
}
