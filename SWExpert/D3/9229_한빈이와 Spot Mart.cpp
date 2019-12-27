#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, N, M, ans, tmp;
vector<int> a;
string answer;

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		a.clear();
		ans = -1;
		tmp = 0;
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
		{
			cin >> tmp;
			a.push_back(tmp);
		}

		int max = 0;
		int sum = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				sum = a[i] + a[j];
				if (sum <= M && sum > max)
				{
					ans = sum;
					max = sum;
				}
			}
		}

		answer.append("#").append(to_string(tc)).append(" ").append(to_string(ans)).append("\n");
	}
	cout << answer;
	return 0;
}
