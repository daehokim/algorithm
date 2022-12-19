#include <iostream>
using namespace std;

int N;
int arr[1000][10];
const int mod = 10007;
int main(void)
{
	for (int i = 0; i < 10; ++i) {
		arr[0][i] = 1;
	}
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		arr[i][0] = arr[i - 1][0];
		for (int j = 1; j < 10; ++j) {
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % mod;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum += arr[N - 1][i];
	}
	printf("%d\n", sum%mod);
	return 0;
}
