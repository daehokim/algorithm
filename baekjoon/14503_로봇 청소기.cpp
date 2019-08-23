#include<stdio.h>

int n, m, d, ans;
int **map;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void cleaning(int, int);

int main() {
	int r, c;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	map = new int*[n];
	for (int i = 0; i < n; ++i) {
		map[i] = new int[m];
		for (int j = 0; j < m; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	ans = 2;
	map[r][c] = ans++;
	cleaning(r, c);
	printf("%d\n", ans-2);
	return 0;
}

void cleaning(int r, int c) {
	int i = 0;
	int x, y;
 	for (; i < 4; ++i) {
		d = d - 1 < 0 ? 3 : d - 1;
		x = r + dir[d][0];
		y = c + dir[d][1];
		if (map[x][y] == 0) {
			map[x][y] = ans++;
			cleaning(x, y);
			return;
		}
	}
	if (i == 4) {
		x = r - dir[d][0];
		y = c - dir[d][1];
		if (x > 0 && x < n && y > 0 && y < m && map[x][y] != 1)
			cleaning(x, y);
	}
}
