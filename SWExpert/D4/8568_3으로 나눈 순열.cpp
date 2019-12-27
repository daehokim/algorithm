#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, N, ans, input;
vector<int> m0, m1, m2;
string answer;

int main()
{

	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		ans = 0;
		m0.clear();
		m1.clear();
		m2.clear();
		cin >> N;
		for (int i = 1; i <= N; ++i)
		{
			cin >> input;
			if (i % 3 != input % 3)
			{
				switch (i % 3)
				{
				case 0:
					m0.push_back(input % 3);
					break;
				case 1:
					m1.push_back(input % 3);
					break;
				case 2:
					m2.push_back(input % 3);
					break;
				}
			}
		}

		int i = 0, len = 0;
		while (m0.size() > 0)
		{
			if (m0[0] == 1)
			{
				for (i = 0, len = m1.size(); i < len; ++i)
				{
					if (m1[i] == 0)
					{
						m1.erase(m1.begin() + i);
						break;
					}
				}
				if (i == len)
				{
					m1.pop_back();
					m0.push_back(2);
				}
				m0.erase(m0.begin());
			}
			else
			{
				for (i = 0, len = m2.size(); i < len; ++i)
				{
					if (m2[i] == 0)
					{
						m2.erase(m2.begin() + i);
						break;
					}
				}
				if (i == len)
				{
					m2.pop_back();
					m0.push_back(1);
				}
				m0.erase(m0.begin());
			}
			++ans;
		}
		ans += m1.size();

		answer.append("#").append(to_string(tc)).append(" ").append(to_string(ans)).append("\n");
	}
	cout << answer;
	return 0;
}
