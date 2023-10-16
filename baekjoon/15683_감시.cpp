#include <iostream>
#include <vector>
using namespace std;

#define WALL 6
#define SURVEILLANCE_AREA -1
struct CCTV
{
	int x;
	int y;
	int type;

	CCTV(int _x = 0, int _y = 0, int _type = 0) : x(_x), y(_y), type(_type) {};
};

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int N, M, ANS;
vector<vector<int>> map;
vector<CCTV> cctv_list;

int Surveil(int _x, int _y, int _dir, vector<vector<int>>& _map)
{
	int surveil_cnt = 0;

	while (_x >= 0 && _x < N && _y >= 0 && _y < M)
	{
		if (_map[_x][_y] == WALL)
		{
			break;
		}
		if (_map[_x][_y] == 0 || _map[_x][_y] == 5)
		{
			_map[_x][_y] = SURVEILLANCE_AREA;
			++surveil_cnt;
		}
		_x += dir[_dir][0];
		_y += dir[_dir][1];
	}

	return surveil_cnt;
}

void Counting(int _idx, vector<vector<int>> _map)
{
	if (_idx == cctv_list.size())
	{
		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (_map[i][j] == 0)
				{
					++count;
				}
			}
		}
		if (count < ANS)
		{
			ANS = count;
		}
		return;
	}
	int surveil_cnt = 0;
	switch (cctv_list[_idx].type)
	{
	case 1:
		for (int d = 0; d < 4; ++d)
		{
			vector<vector<int>> temp_map = _map;
			surveil_cnt = Surveil(cctv_list[_idx].x, cctv_list[_idx].y, d, temp_map);
			Counting(_idx + 1, temp_map);
		}
		break;
	case 2:
		for (int d = 0; d < 2; ++d)
		{
			vector<vector<int>> temp_map = _map;
			surveil_cnt = Surveil(cctv_list[_idx].x, cctv_list[_idx].y, d, temp_map);
			surveil_cnt += Surveil(cctv_list[_idx].x, cctv_list[_idx].y, d + 2, temp_map);
			Counting(_idx + 1, temp_map);
		}
		break;
	case 3:
		for (int d = 0; d < 4; ++d)
		{
			vector<vector<int>> temp_map = _map;
			surveil_cnt = Surveil(cctv_list[_idx].x, cctv_list[_idx].y, d, temp_map);
			surveil_cnt += Surveil(cctv_list[_idx].x, cctv_list[_idx].y, (d + 1) % 4, temp_map);
			Counting(_idx + 1, temp_map);
		}
		break;
	case 4:
		for (int d = 0; d < 4; ++d)
		{
			vector<vector<int>> temp_map = _map;
			surveil_cnt = Surveil(cctv_list[_idx].x, cctv_list[_idx].y, d, temp_map);
			surveil_cnt += Surveil(cctv_list[_idx].x, cctv_list[_idx].y, (d + 1) % 4, temp_map);
			surveil_cnt += Surveil(cctv_list[_idx].x, cctv_list[_idx].y, (d + 2) % 4, temp_map);
			Counting(_idx + 1, temp_map);
		}
		break;
	}
}
int main()
{
	cin >> N >> M;
	map.resize(N);
	for (int i = 0; i < N; ++i)
	{
		map[i].resize(M);
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != WALL)
			{
				cctv_list.push_back(CCTV(i, j, map[i][j]));
			}
		}
	}
	
	for (int idx = 0; idx < cctv_list.size(); ++idx)
	{
		if (cctv_list[idx].type == 5)
		{
			for (int d = 0; d < 4; ++d)
			{
				Surveil(cctv_list[idx].x, cctv_list[idx].y, d, map);
			}
			cctv_list.erase(cctv_list.begin() + idx);
			--idx;
		}
	}

	ANS = 1234567890;
	Counting(0, map);
	cout << ANS << endl;
}
