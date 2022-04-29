import java.util.Arrays;
import java.util.Scanner;

public class A {
	static int[] memo;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		memo = new int[n + 1];
		Arrays.fill(memo, -1);
		memo[0] = 1;
		memo[1] = 1;
		System.out.println(dp(n));
	}

	static int dp(int m) {
		if (memo[m] > -1) {
			return memo[m];
		}
		boolean[] check = new boolean[10000];
		for (int i = 1; 2 * i <= m; i++) {
			if (2 * dp(m - i) - dp(m - (2 * i)) > 0) {
				check[2 * dp(m - i) - dp(m - (2 * i))] = true;
			}
		}
		int ans = 0;
		for (int i = 1; i < 1000; i++) {
			if (!check[i]) {
				ans = i;
				break;
			}
		}
		return memo[m] = ans;
	}
}
