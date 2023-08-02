#include <iostream>
using namespace std;

int N, M;
int map[500][500];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
		}
	}

	int ans = 0;
	int sum = 0;

	// ㅁㅁㅁㅁ
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M - 3; ++j)
		{
			sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁ
	// ㅁ
	// ㅁ
	// ㅁ
	for (int i = 0; i < N - 3; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁㅁ
	// ㅁㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁ
	// ㅁ
	// ㅁㅁ
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	//     ㅁ
	// ㅁㅁㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			sum = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 2];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁㅁ
	//   ㅁ
	//   ㅁ
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁㅁㅁ
	// ㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	//   ㅁ
	//   ㅁ
	// ㅁㅁ
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j] + map[i + 2][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁ
	// ㅁㅁㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁㅁ
	// ㅁ
	// ㅁ
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁㅁㅁ
	//     ㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁ
	// ㅁㅁ
	//   ㅁ
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	//   ㅁ
	// ㅁㅁ
	// ㅁ
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	//   ㅁㅁ
	// ㅁㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			sum = map[i][j + 1] + map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁㅁ
	//   ㅁㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁㅁㅁ
	//   ㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	//   ㅁ
	// ㅁㅁㅁ
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			sum = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	// ㅁ
	// ㅁㅁ
	// ㅁ
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	//   ㅁ
	// ㅁㅁ
	//   ㅁ
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			sum = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}

	cout << ans;
}
