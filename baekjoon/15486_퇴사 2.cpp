#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N = 0;
	vector<int> t, p;

	cin >> N;
	t.resize(N);
	p.resize(N + 1);
	for (int i = 0; i < N; ++i)
	{
		cin >> t[i] >> p[i];
	}

	int tmp_t = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		if (i + t[i] <= N)
		{
			tmp_t = p[i] + p[i + t[i]];
			p[i] = tmp_t > p[i + 1] ? tmp_t : p[i + 1];
		}
		else
		{
			p[i] = p[i + 1];
		}
	}
	cout << p[0] << endl;

	return 0;
}
