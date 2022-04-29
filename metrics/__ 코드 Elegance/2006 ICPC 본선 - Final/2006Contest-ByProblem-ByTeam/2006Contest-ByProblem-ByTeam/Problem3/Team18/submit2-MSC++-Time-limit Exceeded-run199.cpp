#include <cstdio>

void main() {
	int allcnt = 0;
	scanf("%d", &allcnt);
	for (int i = 0; i < allcnt; i++) {
		int mx, my;
		scanf("%d%d", &my, &mx);
		bool **data = new bool*[mx];
		for (int j = 0; j < mx; j++) {
			data[j] = new bool[my];
			for (int k = 0; k < my; k++) {
				data[j][k] = false;
			}
		}
		int holen;
		scanf("%d", &holen);
		for (int j = 0; j < holen; j++) {
			int x, y;
			scanf("%d%d", &y, &x);
			x = mx - x;
			if (x > 0 && y > 0) data[x - 1][y - 1] = true;
			if (x > 0 && y < my) data[x - 1][y] = true;
			if (x < mx && y > 0) data[x][y - 1] = true;
			if (x < mx && y < my) data[x][y] = true;
		}

		int toout = 99999;
		int holex = -1;
		int holey = -1;

		// HO Bound
		for (int j = 0; j < mx; j++) {
			int ln = -1, rn = -1;
			for (int k = 0; k < my; k++) {
				if (ln == -1 && data[j][k]) { ln = k; }
				if (rn == -1 && data[j][my - k - 1]) { rn = my - k - 1; }
			}
			//printf("> %d %d : ", ln, rn);
			//printf("%d (%d,%d)\n", toout, holex, holey);
			if (ln != -1 && rn != -1) {
				if (rn - ln >= 0 && my - (rn - ln) < toout) {
					toout = my - (rn - ln);
					holex = j;
					holey = -1;
				}
				for (int k = ln; k < rn; k++) {
					data[j][k] = true;
				}
			}
		}

		//printf("VT-----------------\n");

		// VT Bound
		for (int j = 0; j < my; j++) {
			int ln = -1, rn = -1;
			for (int k = 0; k < mx; k++) {
				if (ln == -1 && data[k][j]) { ln = k; }
				if (rn == -1 && data[mx - k - 1][j]) { rn = mx - k - 1; }
			}
			//printf("> %d %d : ", ln, rn);
			//printf("%d (%d,%d)\n", toout, holex, holey);
			if (ln != -1 && rn != -1) {
				if (rn - ln >= 0 && mx - (rn - ln) < toout) {
					toout = mx - (rn - ln);
					holex = -1;
					holey = j;
				}
				for (int k = ln; k < rn; k++) {
					data[k][j] = true;
				}
			}
		}

		if (holex == -1) {
			for (int j = 0; j < mx; j++) {
				data[j][holey] = true;
			}
		}
		if (holey == -1) {
			for (int j = 0; j < my; j++) {
				data[holex][j] = true;
			}
		}

		//// HO Bound
		//for (int j = 0; j < mx; j++) {
		//	int ln = -1, rn = -1;
		//	for (int k = 0; k < my; k++) {
		//		if (ln == -1 && data[j][k]) { ln = k; }
		//		if (rn == -1 && data[j][my - k - 1]) { rn = my - k - 1; }
		//	}
		//	//printf("> %d %d : ", ln, rn);
		//	//printf("%d (%d,%d)\n", toout, holex, holey);
		//	if (ln != -1 && rn != -1) {
		//		if (rn - ln >= 0 && my - (rn - ln) < toout) {
		//			toout = my - (rn - ln);
		//			holex = j;
		//			holey = -1;
		//		}
		//		for (int k = ln; k < rn; k++) {
		//			data[j][k] = true;
		//		}
		//	}
		//}

		////printf("VT-----------------\n");

		//// VT Bound
		//for (int j = 0; j < my; j++) {
		//	int ln = -1, rn = -1;
		//	for (int k = 0; k < mx; k++) {
		//		if (ln == -1 && data[k][j]) { ln = k; }
		//		if (rn == -1 && data[mx - k - 1][j]) { rn = mx - k - 1; }
		//	}
		//	//printf("> %d %d : ", ln, rn);
		//	//printf("%d (%d,%d)\n", toout, holex, holey);
		//	if (ln != -1 && rn != -1) {
		//		if (rn - ln >= 0 && mx - (rn - ln) < toout) {
		//			toout = mx - (rn - ln);
		//			holex = -1;
		//			holey = j;
		//		}
		//		for (int k = ln; k < rn; k++) {
		//			data[k][j] = true;
		//		}
		//	}
		//}


		int alln = 0;

		for (int j = 0; j < mx; j++) {
			for (int k = 0; k < my; k++) {
				if (data[j][k]) alln++;
			}
		}
		printf("%d\n", alln);


		//for (int j = 0; j < mx; j++) {
		//	for (int k = 0; k < my; k++) {
		//		if (data[j][k]) printf("O "); else printf(". ");
		//	}

		//	printf("\n");
		//}
	}
}