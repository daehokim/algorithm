#include <iostream>
using namespace std;

int dir[4][2] = { {0,-1}, {1,0}, {0,1}, {-1, 0} };
int N, A[500][500];
int ans;

void SpreadDust(int _x, int _y, int _dust)
{
	if (_x >= 0 && _y >= 0 && _x < N && _y < N)
	{
		A[_x][_y] += _dust;
	}
	else
	{
		ans += _dust;
	}
}

void MoveTornado(int _to_x, int _to_y, int _dir)
{
	int x = 0, y = 0, dust = 0, last_dust = A[_to_x][_to_y];

	int left = (_dir + 1) % 4;
	int back = (_dir + 2) % 4;
	int right = (_dir + 3) % 4;
	// 왼쪽 앞 10%
	x = _to_x + dir[_dir][0] + dir[left][0];
	y = _to_y + dir[_dir][1] + dir[left][1];
	dust = A[_to_x][_to_y] * 10 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 왼쪽 7%
	x = _to_x + dir[left][0];
	y = _to_y + dir[left][1];
	dust = A[_to_x][_to_y] * 7 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 왼쪽 2%
	x = _to_x + dir[left][0] * 2;
	y = _to_y + dir[left][1] * 2;
	dust = A[_to_x][_to_y] * 2 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 왼쪽 뒤 1%
	x = _to_x + dir[back][0] + dir[left][0];
	y = _to_y + dir[back][1] + dir[left][1];
	dust = A[_to_x][_to_y] * 1 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 오른쪽 10%
	x = _to_x + dir[_dir][0] + dir[right][0];
	y = _to_y + dir[_dir][1] + dir[right][1];
	dust = A[_to_x][_to_y] * 10 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 오른쪽 7%
	x = _to_x + dir[right][0];
	y = _to_y + dir[right][1];
	dust = A[_to_x][_to_y] * 7 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 오른쪽 2%
	x = _to_x + dir[right][0] * 2;
	y = _to_y + dir[right][1] * 2;
	dust = A[_to_x][_to_y] * 2 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 오른쪽 1%
	x = _to_x + dir[back][0] + dir[right][0];
	y = _to_y + dir[back][1] + dir[right][1];
	dust = A[_to_x][_to_y] * 1 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 앞쪽 5%
	x = _to_x + dir[_dir][0] * 2;
	y = _to_y + dir[_dir][1] * 2;
	dust = A[_to_x][_to_y] * 5 / 100;
	SpreadDust(x, y, dust);
	last_dust -= dust;

	// 앞쪽 a
	x = _to_x + dir[_dir][0];
	y = _to_y + dir[_dir][1];
	SpreadDust(x, y, last_dust);

	A[_to_x][_to_y] = 0;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> A[i][j];
		}
	}
	ans = 0;

	int x = N / 2, y = N / 2, d = 0;
	int moving_length = 1;
	for (int i = 1, size = N; i < size; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < moving_length; ++k)
			{
				x += dir[d][0];
				y += dir[d][1];
				MoveTornado(x, y, d);
			}
			d = (d + 1) % 4;
		}
		++moving_length;
	}

	// 마지막 (0,0) 이동
	for (int i = 1; i < N; ++i)
	{
		x += dir[0][0];
		y += dir[0][1];
		MoveTornado(x, y, 0);
	}

	cout << ans << endl;
	return 0;
}
