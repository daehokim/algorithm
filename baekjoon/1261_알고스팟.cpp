#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int N, M, x, y, ans;
vector<vector<int>> map;
vector<vector<int>> dist;
queue<pair<int, int>> q;
char input[101];

int main()
{
	cin >> N >> M;
	map.resize(M);
	dist.resize(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		dist[i].resize(N);
		for (int j = 0; j < N; ++j)
		{
			map[i].push_back(input[j]-'0');
			dist[i][j] = 1234567890;
		}
	}
	dist[0][0] = 0;
	ans = 0;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; ++d)
		{
			int a = x + dir[d][0];
			int b = y + dir[d][1];
				
			if (a >= 0 && b >= 0 && a < M && b < N)
			{
				if (map[a][b] == 0)
				{
					if (dist[a][b] > dist[x][y]) {
						dist[a][b] = dist[x][y];
						q.push(make_pair(a, b));
					}
				}
				else
				{
					if (dist[a][b] > dist[x][y]+1) {
						dist[a][b] = dist[x][y]+1;
						q.push(make_pair(a, b));
					}
				}
			}
		}
	}
	cout << dist[M - 1][N - 1] << endl;
	return 0;
}
