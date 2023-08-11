#include <iostream>
#include <vector>
using namespace std;

long long n;

#define MOD 1000000
typedef vector<long long> Matrix;
Matrix F;

Matrix Multiply(Matrix _a, Matrix _b)
{
	Matrix ret(4);
	ret[0] = (_a[0] * _b[0] + _a[1] * _b[2]) % MOD;
	ret[1] = (_a[0] * _b[1] + _a[1] * _b[3]) % MOD;
	ret[2] = (_a[2] * _b[0] + _a[3] * _b[2]) % MOD;
	ret[3] = (_a[2] * _b[1] + _a[3] * _b[3]) % MOD;

	return ret;
}

Matrix Square(long long _exp)
{
	if (_exp == 1)
	{
		return F;
	}
	else if (_exp % 2 == 1)
	{
		return Multiply(Square(_exp - 1), F);
	}
	else
	{
		Matrix temp = Square(_exp / 2);
		return Multiply(temp, temp);
	}
}

int main()
{
	cin >> n;

	F.assign({ 1,1,1,0 });
	
	Matrix ans = Square(n);

	cout << ans[1] << endl;
}
