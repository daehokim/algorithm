#include <iostream>
using namespace std;

int N;

int main()
{
	cin >> N;
	
	long long* fibo = new long long[N + 1];
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cout << fibo[N] << endl;

	delete[] fibo;
	return 0;
}
