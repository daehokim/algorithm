#include<stdio.h>

int x1, y1, x2, y2, r1, r2, ans, d1, d2, d3;

int dist() {
	int dx, dy;
	if (x1 < x2) dx = x2 - x1;
	else dx = x1 - x2;
	if (y1 < y2) dy = y2 - y1;
	else dy = y1 - y2;

	return dx * dx + dy * dy;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		ans = 0;
		d1 = dist();
		d2 = (r1 + r2)*(r1 + r2);
		d3 = (r1 - r2)*(r1 - r2);
		if (d1 == 0 && d3 == 0) {
			ans = -1;
		}
		else if (d1 < d2 && d1 > d3) {
			ans = 2;
		}
		else if (d1 == d2 || d1 == d3) {
			ans = 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
