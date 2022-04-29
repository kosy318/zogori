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
			bound_rx[i] = 0;
		}
		for (int i = 0; i < my; i++) {
			bound_ly[i] = 999999;
			bound_ry[i] = 0;
		}

		int minn = 99999;
		int minx = -1;
		int miny = -1;

		int holen;
		scanf("%d", &holen);
		for (int j = 0; j < holen; j++) {
			int x, y;
			scanf("%d%d", &y, &x);
			x = mx - x;
			if (x > 0 && y > 0) {
				if (x - 1 < bound_lx[y - 1]) bound_lx[y - 1] = x - 1;
				if (y - 1 < bound_ly[x - 1]) bound_ly[x - 1] = y - 1;
				if (x - 1 > bound_rx[y - 1]) bound_rx[y - 1] = x - 1;
				if (y - 1 > bound_ry[x - 1]) bound_ry[x - 1] = y - 1;
			}
			if (x > 0 && y < my) {
				if (x - 1 < bound_lx[y]) bound_lx[y] = x - 1;
				if (y < bound_ly[x - 1]) bound_ly[x - 1] = y;
				if (x - 1 > bound_rx[y]) bound_rx[y] = x - 1;
				if (y > bound_ry[x - 1]) bound_ry[x - 1] = y;
			}
			if (x < mx && y > 0) {
				if (x < bound_lx[y - 1]) bound_lx[y - 1] = x;
				if (y - 1 < bound_ly[x]) bound_ly[x] = y - 1;
				if (x > bound_rx[y - 1]) bound_rx[y - 1] = x;
				if (y - 1 > bound_ry[x]) bound_ry[x] = y - 1;
			}
			if (x < mx && y < my) {
				if (x < bound_lx[y]) bound_lx[y] = x;
				if (y < bound_ly[x]) bound_ly[x] = y;
				if (x > bound_rx[y]) bound_rx[y] = x;
				if (y > bound_ry[x]) bound_ry[x] = y;
			}
		}

		for (int i = 0; i < my; i++) {
			int result = mx - (bound_ry[i] - bound_ly[i]);
			if (result >= 0 && result < minn) {
				minn = result;
				minx = -1;
				miny = i;
			}
//			printf("> %d %d\n", bound_ly[i], bound_ry[i]);
		}
		for (int i = 0; i < mx; i++) {
			int result = my - (bound_rx[i] - bound_lx[i]);
			if (result >= 0 && result < minn) {
				minn = result;
				minx = i;
				miny = -1;
			}
//			printf(">> %d %d\n", bound_lx[i], bound_rx[i]);
		}
		if (minx == -1) {
			bound_ly[miny] = 0;
			bound_ry[miny] = mx;
		}
		if (miny == -1) {
			bound_lx[minx] = 0;
			bound_rx[minx] = my;
		}

		for (int i = 0; i < mx; i++) {
			for (int j = 0; j < my; j++) {
			}
		}

//		printf(">>> %d %d\n", minx, miny);

		int alln = 0;

		for (int i = 0; i < mx; i++)
			alln += bound_rx[i] - bound_lx[i] + 1;

		printf("%d\n", alln);

	}
}