#include <iostream>
#include <queue>
using namespace std;

int N, L, ans;
int map[100][100];

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
		}
	}

	ans = 0;
	//가로
	for (int i = 0; i < N; ++i)
	{
		int current_height = map[i][0];
		int counting = 1;
		int j = 1;
		for (; j < N; ++j)
		{
			const int diff = map[i][j] - current_height;
			if (diff == 0)
			{
				++counting;
			}
			else if (diff == 1)
			{
				if (counting < L)
				{
					break;
				}
				counting = 1;
				current_height = map[i][j];
			}
			else if (diff == -1)
			{
				int temp_height = map[i][j];
				int k = j + L;
				for (; j < k && j < N; ++j)
				{
					if (temp_height != map[i][j])
					{
						break;
					}
				}
				if (j != k)
				{
					j = 0;
					break;
				}
				counting = 0;
				--j;
				current_height = temp_height;
			}
			else
			{
				break;
			}
		}
		if (j == N)
		{
			++ans;
		}
	}

	//세로
	for (int i = 0; i < N; ++i)
	{
		int current_height = map[0][i];
		int counting = 1;
		int j = 1;
		for (; j < N; ++j)
		{
			const int diff = map[j][i] - current_height;
			if (diff == 0)
			{
				++counting;
			}
			else if (diff == 1)
			{
				if (counting < L)
				{
					break;
				}
				counting = 1;
				current_height = map[j][i];
			}
			else if (diff == -1)
			{
				int temp_height = map[j][i];
				int k = j + L;
				for (; j < k && j < N; ++j)
				{
					if (temp_height != map[j][i])
					{
						break;
					}
				}
				if (j != k)
				{
					j = 0;
					break;
				}
				counting = 0;
				--j;
				current_height = temp_height;
			}
			else
			{
				break;
			}
		}
		if (j == N)
		{
			++ans;
		}
	}

	cout << ans << endl;
	return 0;
}
