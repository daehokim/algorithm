#include <iostream>
using namespace std;

int E, S, M;

int main()
{
	cin >> E >> S >> M;
	int e = 15, s = 28, m = 19;
	for (int i = 0; i < e*s*m; ++i)
	{
		if (i%e == E - 1 && i%s == S - 1 && i%m == M - 1)
		{
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}
