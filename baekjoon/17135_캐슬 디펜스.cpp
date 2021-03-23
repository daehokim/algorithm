#include <iostream>
using namespace std;

int n, m, d;
int field[15][15];
int answer;

int play(int, int, int);

int main(void)
{
	scanf("%d %d %d", &n, &m, &d);

	field[15][15] = { 0, };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &field[i][j]);
		}
	}

	answer = 0;
	for (int i = 0; i < m - 2; ++i)
	{
		for (int j = i + 1; j < m - 1; ++j)
		{
			for (int k = j + 1; k < m; ++k)
			{
				int temp = play(i, j, k);
				if (answer <= temp)
				{
					answer = temp;
				}
			}
		}
	}

	printf("%d", answer);

	return 0;
}

int play(int _archer_1, int _archer_2, int _archer_3)
{
	int result = 0;
	int dead[15][15] = { 0, };

	for (int current_line = n; current_line > 0; --current_line)
	{
		int archer_1_shot = 0;
		int archer_2_shot = 0;
		int archer_3_shot = 0;

		for (int distance = 1; distance <= d; ++distance)
		{
			for (int j = 0; j < m; ++j)
			{
				for (int i = current_line - 1; i >= 0 && i >= current_line - distance; --i)
				{
					if (field[i][j]
						&& !dead[i][j]
						&& !archer_1_shot
						&& (current_line - i) + (_archer_1 > j ? _archer_1 - j : j - _archer_1) <= distance)
					{
						archer_1_shot = i * 100 + j == 0 ? -1 : i * 100 + j;
					}
					if (field[i][j]
						&& !dead[i][j]
						&& !archer_2_shot
						&& (current_line - i) + (_archer_2 > j ? _archer_2 - j : j - _archer_2) <= distance)
					{
						archer_2_shot = i * 100 + j == 0 ? -1 : i * 100 + j;
					}
					if (field[i][j]
						&& !dead[i][j]
						&& !archer_3_shot
						&& (current_line - i) + (_archer_3 > j ? _archer_3 - j : j - _archer_3) <= distance)
					{
						archer_3_shot = i * 100 + j == 0 ? -1 : i * 100 + j;
					}
					if (archer_1_shot && archer_2_shot && archer_3_shot)
					{
						break;
					}
				}
				if (archer_1_shot && archer_2_shot && archer_3_shot)
				{
					break;
				}
			}
			if (archer_1_shot && archer_2_shot && archer_3_shot)
			{
				break;
			}
		}
		if (archer_1_shot)
		{
			if (archer_1_shot == -1)
			{
				archer_1_shot = 0;
			}
			dead[archer_1_shot / 100][archer_1_shot % 100] = true;
			++result;
		}
		if (archer_2_shot)
		{
			if (archer_2_shot == -1)
			{
				archer_2_shot = 0;
			}
			if (!dead[archer_2_shot / 100][archer_2_shot % 100])
			{
				dead[archer_2_shot / 100][archer_2_shot % 100] = true;
				++result;
			}
		}
		if (archer_3_shot)
		{
			if (archer_3_shot == -1)
			{
				archer_3_shot = 0;
			}
			if (!dead[archer_3_shot / 100][archer_3_shot % 100])
			{
				dead[archer_3_shot / 100][archer_3_shot % 100] = true;
				++result;
			}
		}
	}

	return result;
}
