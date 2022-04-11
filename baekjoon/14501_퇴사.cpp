#include <iostream>
using namespace std;

int N;
int T[15] = { 0, };
int P[15] = { 0, };
int ans[16] = { 0, };

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> T[i] >> P[i];
	}
	
	if (T[N - 1] == 1)
	{
		ans[N - 1] = P[N - 1];
	}
	for (int date = N - 1; date >= 0; --date)
	{
		if (date + T[date] <= N)
		{
			int temp = ans[date + T[date]] + P[date];
			if (temp > ans[date + 1])
			{
				ans[date] = temp;
			}
			else
			{
				ans[date] = ans[date + 1];
			}
		}
		else
		{
			ans[date] = ans[date + 1];
		}
	}

	cout << ans[0] << endl;
	return 0;
}
