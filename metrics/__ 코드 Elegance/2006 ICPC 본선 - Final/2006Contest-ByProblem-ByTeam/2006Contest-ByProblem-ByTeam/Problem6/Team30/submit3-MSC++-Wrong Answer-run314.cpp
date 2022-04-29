#include <iostream>
#include <numeric>
#include <cassert>
using namespace std;


int main(void)
{
	int T, n, a[20], b[20], x[20], M, G, i;
	bool impossible;
	cin >> T;

	while (T) {
		--T;

		cin >> n;
		for (i = 0; i < n; ++i)
			cin >> a[i] >> b[i];
		cin >> M;

		impossible = true;
		for (x[0] = 1; x[0] <= M; ++x[0]) {
			G = a[0] * x[0] + b[0];

			for (i = 1; i < n; ++i)
				if ( (G - b[i]) % a[i] == 0 ) {
					x[i] = (G - b[i]) / a[i];

					if (x[i] == 0)
						break;
				}
				else
					break;

			if (i == n && accumulate(x, x + n, 0) == M) {
				cout << G << endl;
				impossible = false;
				break;
			}
		}

		if (impossible)
			cout << 0 << endl;
	}

	return 0;
}