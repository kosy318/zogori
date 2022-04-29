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
			bound_lx[i] = 999999;
			bound_rx[i] = -1;
		}
		for (int i = 0; i < my; i++) {
			bound_ly[i] = 999999;
			bound_ry[i] = -1;
		}

		int holen;
		scanf("%d", &holen);
		if (holen == 0) {
			if (mx < my) printf("%d\n", mx);
			else printf("%d\n", my);
			continue;
		}
		for (int j = 0; j < holen; j++) {
			int x, y;
			scanf("%d%d", &y, &x);
			x = mx - x;
			if (x > 0 && y > 0) {
				if (x - 1 < bound_ly[y - 1]) bound_ly[y - 1] = x - 1;
				if (y - 1 < bound_lx[x - 1]) bound_lx[x - 1] = y - 1;
				if (x - 1 > bound_ry[y - 1]) bound_ry[y - 1] = x - 1;
				if (y - 1 > bound_rx[x - 1]) bound_rx[x - 1] = y - 1;
				if (bound_ly[y - 1] < 99999 && bound_ry[y - 1] >= 0) {
					for (int i = bound_ly[y - 1]; i <= bound_ry[y - 1]; i++) {
						if (bound_lx[i] < 999999 && bound_rx[i] >= 0) {
							if (bound_lx[i] > y - 1) bound_lx[i] = y - 1;
						}
					}
				}
			}
			if (x > 0 && y < my) {
				if (x - 1 < bound_ly[y]) bound_ly[y] = x - 1;
				if (y < bound_lx[x - 1]) bound_lx[x - 1] = y;
				if (x - 1 > bound_ry[y]) bound_ry[y] = x - 1;
				if (y > bound_rx[x - 1]) bound_rx[x - 1] = y;
				if (bound_ly[y] < 99999 && bound_ry[y] >= 0) {
					for (int i = bound_ly[y]; i <= bound_ry[y]; i++) {
						if (bound_lx[i] < 999999 && bound_rx[i] >= 0) {
							if (bound_rx[i] < y) bound_rx[i] = y;
						}
					}
				}
			}
			if (x < mx && y > 0) {
				if (x < bound_ly[y - 1]) bound_ly[y - 1] = x;
				if (y - 1 < bound_lx[x]) bound_lx[x] = y - 1;
				if (x > bound_ry[y - 1]) bound_ry[y - 1] = x;
				if (y - 1 > bound_rx[x]) bound_rx[x] = y - 1;
				if (bound_ly[y - 1] < 99999 && bound_ry[y - 1] >= 0) {
					for (int i = bound_ly[y - 1]; i <= bound_ry[y - 1]; i++) {
						if (bound_lx[i] < 999999 && bound_rx[i] >= 0) {
							if (bound_lx[i] > y - 1) bound_lx[i] = y - 1;
						}
					}
				}
			}
			if (x < mx && y < my) {
				if (x < bound_ly[y]) bound_ly[y] = x;
				if (y < bound_lx[x]) bound_lx[x] = y;
				if (x > bound_ry[y]) bound_ry[y] = x;
				if (y > bound_rx[x]) bound_rx[x] = y;
				if (bound_ly[y] < 99999 && bound_ry[y] >= 0) {
					for (int i = bound_ly[y]; i <= bound_ry[y]; i++) {
						if (bound_lx[i] < 999999 && bound_rx[i] >= 0) {
							if (bound_rx[i] < y) bound_rx[i] = y;
						}
					}
				}
			}
		}

		// Search
		int minn = 99999;
		for (int i = 0; i < my; i++) {
			int result = mx - (bound_ry[i] - bound_ly[i]);
			if (result >= 0 && result < minn) {
				minn = result;
			}
//			printf("> %d %d [%d]\n", bound_ly[i], bound_ry[i], result);
		}
		for (int i = 0; i < mx; i++) {
			int result = my - (bound_rx[i] - bound_lx[i]);
			if (result >= 0 && result < minn) {
				minn = result;
			}
//			printf(">> %d %d [%d]\n", bound_lx[i], bound_rx[i], result);
		}

		// CheckUp
		int mindata = 99999999;
		for (int i = 0; i < my; i++) {
			int result = mx - (bound_ry[i] - bound_ly[i]);
			if (result == minn) {
				int myadd = minn - 1;
				for (int j = 0; j <= mx; j++) {
					if (bound_lx[j] < 999999 && bound_rx[j] >= 0) {
						if (bound_lx[j] > i) myadd += bound_lx[j] - i - 1;
						if (bound_rx[j] < i) myadd += i - bound_rx[j] - 1;
					}
				}
				if (mindata > myadd) mindata = myadd;
//				printf(">>> %d %d [%d]\n", i, -1, myadd);
			}
		}
		for (int i = 0; i < mx; i++) {
			int result = my - (bound_rx[i] - bound_lx[i]);
			if (result == minn) {
				int myadd = minn - 1;
				for (int j = 0; j <= my; j++) {
					if (bound_ly[j] < 999999 && bound_ry[j] >= 0) {
						if (bound_ly[j] > i) myadd += bound_ly[j] - i - 1;
						if (bound_ry[j] < i) myadd += i - bound_ry[j] - 1;
					}
				}
				if (mindata > myadd) mindata = myadd;
//				printf(">>>> %d %d [%d]\n", -1, i, myadd);
			}
		}

//		printf(">>> %d %d\n", minx, miny);

		int alln = 0;

		for (int i = 0; i < mx; i++) {
			if (bound_lx[i] < 999999 && bound_rx[i] >= 0) {
				//printf("]]]] %d %d\n", bound_lx[i], bound_rx[i]);
				
				alln += bound_rx[i] - bound_lx[i] + 1;
			}
		}
		printf("%d\n", alln + mindata);
	}
}