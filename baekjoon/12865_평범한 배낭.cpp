#include <iostream>
using namespace std;

int N, K;
int weight[101], value[101];
int dp[101][100001];

int Max(int _a, int _b)
{
	return _a > _b ? _a : _b;
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> weight[i] >> value[i];
	}

	int temp_value;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			if (j - weight[i] >= 0)
			{
				dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];
}
