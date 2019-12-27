#include <iostream>
#include <string>
using namespace std;

int T;
long long N;
string answer, ans;

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		ans = "YES";
		cin >> N;
		while (N > 1)
		{
			if (N % 2 == 0) N /= 2;
			else
			{
				ans = "NO";
				break;
			}
		}
		answer.append("#").append(to_string(tc)).append(" ").append(ans).append("\n");
	}
	cout << answer;
	return 0;
}
