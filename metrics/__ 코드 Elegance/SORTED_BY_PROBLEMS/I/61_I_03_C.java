import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class I {
	static int n;
	static T[] t;

	public static void main(String[] args) throws IOException {
		input();
		solve();
	}

	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		t = new T[n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			t[i] = new T(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
	}

	static void solve() {
		Arrays.sort(t);
		System.out.print(bs(0, Integer.MAX_VALUE));
	}

	static long bs(long min, long max) {
		if (min == max) {
			return min;
		}
		long mid = (min + max) / 2 + 1;
		long last = t[0].x;
		boolean can = true;
		for (int i = 1; i < n; i++) {
			if (last + mid < t[i].x) {
				last = t[i].x;
			} else if (last + mid <= t[i].x + t[i].l) {
				last = last + mid;
			} else {
				can = false;
				break;
			}
		}
		if (can) {
			return bs(mid, max);
		} else {
			return bs(min, mid - 1);
		}
	}
}

class T implements Comparable<T> {
	int x, l;

	T(int x, int l) {
		this.x = x;
		this.l = l;
	}

	@Override
	public int compareTo(T o) {
		if (this.x > o.x) {
			return 1;
		} else if (this.x == o.x) {
			return 0;
		} else {
			return -1;
		}
	}
}
