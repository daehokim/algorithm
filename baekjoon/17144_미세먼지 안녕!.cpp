#include <iostream>
#include <queue>
using namespace std;

typedef struct Dust {
	int x;
	int y;
	int size;
	Dust(int _x, int _y, int _size)
	{
		x = _x;
		y = _y;
		size = _size;
	}
	Dust() {};
}Dust;

int R, C, T;
int map[50][50];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
queue<Dust> dust_list;
int air_cleaner[2];

void SpreadDust()
{
	queue<Dust> spread_dust_list;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] > 0)
			{
				int cnt = 0;
				for (int d = 0; d < 4; ++d)
				{
					int x = i + dir[d][0];
					int y = j + dir[d][1];
					if (x >= 0 && x < R && y >= 0 && y < C && map[x][y] != -1)
					{
						spread_dust_list.push(Dust(x, y, map[i][j] / 5));
						++cnt;
					}
				}
				map[i][j] -= (map[i][j] / 5) * cnt;
			}
		}
	}
	while (!spread_dust_list.empty())
	{
		Dust spread_dust = spread_dust_list.front();
		spread_dust_list.pop();
		map[spread_dust.x][spread_dust.y] += spread_dust.size;
	}
}

void Refresh()
{
	for (int i = air_cleaner[0] - 1; i > 0; --i)
	{
		map[i][0] = map[i - 1][0];
	}
	for (int i = air_cleaner[1] + 1; i < R - 1; ++i)
	{
		map[i][0] = map[i + 1][0];
	}

	for (int j = 0; j < C - 1; ++j)
	{
		map[0][j] = map[0][j + 1];
		map[R - 1][j] = map[R - 1][j + 1];
	}

	for (int i = 0; i < air_cleaner[0]; ++i)
	{
		map[i][C - 1] = map[i + 1][C - 1];
	}
	for (int i = R - 1; i > air_cleaner[1]; --i)
	{
		map[i][C - 1] = map[i - 1][C - 1];
	}

	for (int j = C - 1; j > 1; --j)
	{
		map[air_cleaner[0]][j] = map[air_cleaner[0]][j - 1];
		map[air_cleaner[1]][j] = map[air_cleaner[1]][j - 1];
	}
	
	map[air_cleaner[0]][1] = 0;
	map[air_cleaner[1]][1] = 0;
}

int main()
{
	cin >> R >> C >> T;
	int cnt = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				if (cnt++ == 0)
				{
					air_cleaner[0] = i;
					air_cleaner[1] = i + 1;
				}
			}
		}
	}

	for (int i = 0; i < T; ++i)
	{
		SpreadDust();
		Refresh();
	}
	
	int answer = 2;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			answer += map[i][j];
		}
	}

	cout << answer << endl;
	
	return 0;
}
