#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, tmp;
vector<int> wine;
vector<vector<int>> dp;

int main()
{
	scanf("%d", &n);
	wine.resize(n);
	dp.resize(n+1);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &wine[i]);
		dp[i].resize(3);
	}
	dp[n].resize(3);
	for(int i = 1; i <= n; ++i)
	{
		dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
		dp[i][2] = dp[i-1][1]+wine[i-1];
		dp[i][1] = dp[i-1][0]+wine[i-1];
	}
	printf("%d\n", max(dp[n][0], max(dp[n][1], dp[n][2])));

	return 0;
}
