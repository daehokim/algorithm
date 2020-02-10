#include <stdio.h>
#include <vector>
using namespace std;

int w, h, cnt;
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
vector<vector<int>> map;

void search(int row, int col)
{
	map[row][col] = -1;
	for(int d = 0; d < 8; ++d)
	{
		int x = row + dir[d][0];
		int y = col + dir[d][1];
		if(x >= 0 && x < h && y >= 0 && y < w && map[x][y] == 1) search(x, y);
	}
}

int main()
{
	scanf("%d %d", &w, &h);
	do
	{
		cnt = 0;
		map.clear();
		map.resize(h);
		for(int i = 0; i < h; ++i)
		{
			map[i].resize(w);
			for(int j = 0; j < w; ++j)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for(int i = 0; i < h; ++i)
		{
			for(int j = 0; j < w; ++j)
			{
				if(map[i][j] == 1)
				{
					++cnt;
					search(i, j);
				}
			}
		}
		printf("%d\n", cnt);
		scanf("%d %d", &w, &h);
	}while(w != 0);
	return 0;
}
