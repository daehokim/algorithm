#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int W, H;
char map[100][100];
queue<pair<int, int>> laser;

int main()
{
	cin >> W >> H;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C')
			{
				laser.push({ i, j });
			}
		}
	}

	laser.pop();	// 2 개 중 1개 삭제
	int ans = 0;
	int next_x = 0, next_y = 0;
	bool find = false;
	map[laser.back().first][laser.back().second] = '*';
	while (find == false)
	{
		for (int i = 0, cnt = laser.size(); i < cnt; ++i)
		{
			pair<int, int> cur_laser = laser.front();
			laser.pop();
			for (int d = 0; d < 4; ++d)
			{
				next_x = cur_laser.first + dir[d][0];
				next_y = cur_laser.second + dir[d][1];
				while (next_x >= 0 && next_x < H && next_y >= 0 && next_y < W)
				{
					if (map[next_x][next_y] == '.')
					{
						map[next_x][next_y] = '+';
						laser.push({ next_x, next_y });
					}
					else if (map[next_x][next_y] == '*') // 벽 탈출
					{
						break;
					}
					else if (map[next_x][next_y] == 'C')
					{
						find = true;
						break;
					}
					next_x += dir[d][0];
					next_y += dir[d][1];
				}
				if (find == true)
				{
					break;
				}
			}
			if (find == true)
			{
				break;
			}
		}
		++ans;
	}

	cout << ans - 1 << endl;
}
