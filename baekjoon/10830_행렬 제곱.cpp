#include <iostream>
#include <vector>
using namespace std;

int N;
long long B;
vector<vector<int>> matrix, temp_mul;

vector<vector<int>> mul(vector<vector<int>> _a, vector<vector<int>> _b)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			temp_mul[i][j] = 0;
			for (int k = 0; k < N; ++k)
			{
				temp_mul[i][j] += _a[i][k] * _b[k][j];
			}
			temp_mul[i][j] %= 1000;
		}
	}
	return temp_mul;
}

vector<vector<int>> sqr(long long _exp)
{
	if (_exp == 1)
	{
		return matrix;
	}
	
	if (_exp % 2 == 1)
	{
		return mul(matrix, sqr(_exp - 1));
	}
	else
	{
		temp_mul = sqr(_exp / 2);
		return mul(temp_mul, temp_mul);
	}
}
int main()
{
	cin >> N >> B;

	matrix.resize(N);
	temp_mul.resize(N);
	for (int i = 0; i < N; ++i)
	{
		matrix[i].resize(N);
		temp_mul[i].resize(N);
		for (int j = 0; j < N; ++j)
		{
			cin >> matrix[i][j];
			matrix[i][j] %= 1000;
		}
	}

	matrix = sqr(B);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
