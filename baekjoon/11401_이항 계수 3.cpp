#include <iostream>
using namespace std;

#define mod 1000000007
long long N, K, a, b;

long long sqr(long long _a)
{
	if (_a == 0)
	{
		return 1;
	}
	
	if (_a % 2 == 1)
	{
		return b * sqr(_a - 1) % mod;
	}
	else
	{
		long long half = sqr(_a / 2);
		return half * half % mod;
	}
}
int main()
{
	cin >> N >> K;

	a = 1, b = 1;

	for (int i = N; i >= N - K + 1; --i)
	{
		a = (a * i) % mod;
	}

	for (int i = 1; i <= K; ++i)
	{
		b = (b * i) % mod;
	}

	b = sqr(mod - 2);

	cout << a * b % mod << endl;
}
