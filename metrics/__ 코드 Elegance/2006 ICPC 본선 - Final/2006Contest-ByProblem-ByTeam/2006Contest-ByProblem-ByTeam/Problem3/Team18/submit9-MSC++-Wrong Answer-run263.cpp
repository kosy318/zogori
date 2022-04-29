#include <cstdio>

void main() {
	int allcnt = 0;
	scanf("%d", &allcnt);
	for (int xx = 0; xx < allcnt; xx++) {
		int mx, my;
		scanf("%d%d", &my, &mx);
		int *bound_lx = new int[mx];
		int *bound_rx = new int[mx];
		int *bound_ly = new int[my];
		int *bound_ry = new int[my];
		for (int i = 0; i < mx; i++) {
			bound_lx[i] = 0;
			bound_rx[i] = 0;
		}
		for (int i = 0; i < my; i++) {
			bound_ly[i] = 0;
			bound_ry[i] = 0;
		}
		int holen;
		scanf("%d", &holen);
		for (int j = 0; j < holen; j++) {
			int x, y;
			scanf("%d%d", &y, &x);
			x = mx - x;
			if (x > 0 && y > 0) {
				if (x - 1 < bound_lx[y - 1]) bound_lx[y - 1] = x - 1;
				if (y - 1 < bound_ly[x - 1]) bound_ly[x - 1] = y - 1;
			}
			if (x > 0 && y < my) {
				if (x - 1 < bound_lx[y]) bound_lx[y] = x - 1;
				if (y < bound_ly[x - 1]) bound_ly[x - 1] = y;
			}
			if (x < mx && y > 0) {
				if (x < bound_lx[y - 1]) bound_lx[y - 1] = x;
				if (y - 1 < bound_ly[x]) bound_ly[x] = y - 1;
			}
			if (x < mx && y < my) {
				if (x < bound_lx[y]) bound_lx[y] = x;
				if (y < bound_ly[x]) bound_ly[x] = y;
			}
		}

		int toout = 99999;
		int holex = -1;
		int holey = -1;

		// HO Bound
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

		//printf("VT-----------------\n");

		// VT Bound
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

		//if (holex == -1) {
		//	for (int j = 0; j < mx; j++) {
		//		data[j][holey] = true;
		//	}
		//}
		//if (holey == -1) {
		//	for (int j = 0; j < my; j++) {
		//		data[holex][j] = true;
		//	}
		//}

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

		//for (int j = 0; j < mx; j++) {
		//	for (int k = 0; k < my; k++) {
		//		if (data[j][k]) alln++;
		//	}
		//}
		printf("%d\n", alln);


		//for (int j = 0; j < mx; j++) {
		//	for (int k = 0; k < my; k++) {
		//		if (data[j][k]) printf("O "); else printf(". ");
		//	}

		//	printf("\n");
		//}
	}
}