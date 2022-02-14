#include <iostream>
#include <queue>
using namespace std;

struct PIPE
{
	int x;
	int y;
	int dir;

	PIPE()
	{
		x = 0; y = 0; dir = 0;
	}
};

int N, ans;
int dir[3][2] = { 0, 1, 1, 1, 1, 0 };
int house[16][16] = { 0, };
queue<PIPE> pipe;

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> house[i][j];
		}
	}

	ans = 0;
	PIPE p;
	p.y = 1;
	pipe.push(p);
	while (!pipe.empty())
	{
		PIPE current = pipe.front();
		pipe.pop();
		if (current.x == N - 1 && current.y == N - 1 && !house[current.x][current.y])
		{
			++ans;
			continue;
		}
		for (int d = 0; d < 3; ++d)
		{
			if ((current.dir == 0 && d == 2) || (current.dir == 2 && d == 0)) continue;

			PIPE next;
			next.x = current.x + dir[d][0];
			next.y = current.y + dir[d][1];
			next.dir = d;
			if (next.x < N && next.y < N && !house[next.x][next.y])
			{
				if (next.dir == 1 && (house[next.x - 1][next.y] || house[next.x][next.y - 1]))
					continue;
				pipe.push(next);
			}
		}
	}

	cout << ans << endl;

	return 0;
}
