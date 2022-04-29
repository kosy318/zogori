#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
	int T, sh, sm, ss, eh, em, es, sc, ec, counter;

	cin >> T;
	while (T) {
		--T;

		scanf("%d:%d:%d", &sh, &sm, &ss);
		scanf("%d:%d:%d", &eh, &em, &es);

		sc = sh * 10000 + sm * 100 + ss;
		ec = eh * 10000 + em * 100 + es;

		counter = 0;

		while (sc != ec) {
			if (sc % 3 == 0)
				++counter;

			++sc;

			if (sc % 100 % 60 == 0)
				sc += 40;
			if (sc % 10000 % 6000 == 0)
				sc += 4000;
			if (sc % 240000 == 0)
				sc = 0;
		}

		if (ec % 3 == 0)
			++counter;


		cout << counter << endl;
	}

	return 0;
}
