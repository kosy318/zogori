import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class L2 {
	static int n, m;
	static int[] v;
	static Min[] min;
	static int[] memo;

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
		memo = new int[min[m - 1].e + 1];
		System.out.print(dp(min[m - 1].e, m - 1));
	}

	static int dp(int e, int index) {
		if (memo[e] > 0) {
			return memo[e];
		}
		int max = 0;
		for (int i = index; i >= 0; i--) {
			if (min[i].e > e) {
				continue;
			}
			max = Math.max(max, dp(min[i].s, i - 1) + min[i].v);
		}
		return memo[e] = max;
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
