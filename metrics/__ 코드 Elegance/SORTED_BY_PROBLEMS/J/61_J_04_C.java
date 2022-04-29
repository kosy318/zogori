import java.util.Scanner;

public class J {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		System.out.print(solve(n));
	}

	static int solve(int n) {
		n -= 2;
		int sum = 0;
		for (int i = 1;; i++) {
			sum += Math.pow(2, i);
			if (sum >= n) {
				if (sum - Math.pow(2, i - 1) < n) {
					return i * 2 - 1;
				} else {
					return (i - 1) * 2;
				}
			}
		}
	}
}
