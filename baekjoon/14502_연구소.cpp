#include <iostream>
#include <queue>
using namespace std;

typedef struct _Virus
{
	int x, y;
	_Virus(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
}Virus;
int N, M, ans;
int wall_cnt;
int direction[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int map[8][8];
queue<Virus> start_virus;

void BFS(int _idx_i, int _idx_j, int _idx_k)
{
	int temp_map[8][8];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			temp_map[i][j] = map[i][j];
		}
	}
	temp_map[_idx_i / M][_idx_i % M] = 1;
	temp_map[_idx_j / M][_idx_j % M] = 1;
	temp_map[_idx_k / M][_idx_k % M] = 1;

	queue<Virus> virus_list = start_virus;
	int virus_cnt = start_virus.size();
	while (!virus_list.empty())
	{
		Virus cur_virus = virus_list.front();
		virus_list.pop();
		for (int d = 0; d < 4; ++d)
		{
			Virus temp_virus = cur_virus;
			temp_virus.x = cur_virus.x + direction[d][0];
			temp_virus.y = cur_virus.y + direction[d][1];
			if (temp_virus.x >= 0 && temp_virus.x < N && temp_virus.y >= 0 && temp_virus.y < M && temp_map[temp_virus.x][temp_virus.y] == 0)
			{
				temp_map[temp_virus.x][temp_virus.y] = 2;
				++virus_cnt;
				virus_list.push(temp_virus);
			}
		}
	}

	int safety_cnt = N * M - wall_cnt - virus_cnt - 3;
	if (safety_cnt > ans)
	{
		ans = safety_cnt;
	}
}

int main()
{
	cin >> N >> M;
	wall_cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				++wall_cnt;
			}
			else if (map[i][j] == 2)
			{
				Virus temp(i, j);
				start_virus.push(temp);
			}
		}
	}
	int size = N * M;
	ans = 0;
	for (int i = 0; i < size - 2; ++i)
	{
		if (map[i / M][i % M] != 0)
		{
			continue;
		}
		for (int j = i + 1; j < size - 1; ++j)
		{
			if (map[j / M][j % M] != 0)
			{
				continue;
			}
			for (int k = j + 1; k < size; ++k)
			{
				if (map[k / M][k % M] != 0)
				{
					continue;
				}
				BFS(i, j, k);
			}
		}
	}
	

	cout << ans << endl;

	return 0;
}
