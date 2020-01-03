#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

#define INF 2147483647

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int N, M, ans;
string input;
vector<vector<int>> map;
vector<vector<vector<int>>> dist;
queue<pair<pair<int, int>, int>> q;

int main()
{
	cin >> N >> M;
	map.resize(N);
	dist.resize(N);
	for (int i = 0; i < N; ++i)
	{
		map[i].resize(M);
		dist[i].resize(M);
		cin >> input;
		for (int j = 0; j < M; ++j)
		{
			map[i][j] = input.at(j) - '0';
			dist[i][j].push_back(INF);
			dist[i][j].push_back(INF);
		}
	}
	dist[0][0][0] = 1;
	q.push(make_pair(make_pair(0, 0), 0));
	while (!q.empty())
	{
		int currX = q.front().first.first;
		int currY = q.front().first.second;
		int currZ = q.front().second;
		q.pop();
		for (int d = 0; d < 4; ++d)
		{
			int x = currX + dir[d][0];
			int y = currY + dir[d][1];
			if (x >= 0 && y >= 0 && x < N && y < M)
			{
				if (map[x][y] == 0)
				{
					if (currZ == 0 && dist[x][y][currZ] > dist[currX][currY][currZ] + 1)
					{
						dist[x][y][currZ] = dist[currX][currY][currZ] + 1;
						q.push(make_pair(make_pair(x, y), currZ));
					}
					else if (currZ == 1 && dist[x][y][0] == INF && dist[x][y][currZ] > dist[currX][currY][currZ] + 1)
					{
						dist[x][y][currZ] = dist[currX][currY][currZ] + 1;
						q.push(make_pair(make_pair(x, y), currZ));

					}
				}
				else
				{
					if (currZ == 0 && dist[x][y][1] > dist[currX][currY][currZ] + 1)
					{
						dist[x][y][1] = dist[currX][currY][currZ] + 1;
						q.push(make_pair(make_pair(x, y), 1));
					}
				}
			}
		}
	}
	if (dist[N - 1][M - 1][0] == INF && dist[N - 1][M - 1][1] == INF)
	{
		ans = -1;
	}
	else
	{
		ans = dist[N - 1][M - 1][0] < dist[N - 1][M - 1][1] ? dist[N - 1][M - 1][0] : dist[N - 1][M - 1][1];
	}
	cout << ans << endl;

	return 0;
}
