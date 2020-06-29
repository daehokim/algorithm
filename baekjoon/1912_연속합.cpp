#include <iostream>
using namespace std;

int N;
int **arr;

int main(void)
{
	scanf("%d", &N);

	arr = new int*[N];
	for (int i = 0; i < N; ++i) {
		arr[i] = new int[2];
	}

	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i][0]);
	}

	arr[0][1] = arr[0][0] > 0 ? arr[0][0] : 0;
	for (int i = 1; i < N; ++i) {
		int tmp = arr[i - 1][1] + arr[i][0];
		if (arr[i - 1][0] < tmp) {
			arr[i][0] = tmp;
		}
		else {
			arr[i][0] = arr[i - 1][0];
		}
		arr[i][1] = tmp > 0 ? tmp : 0;
	}

	printf("%d\n", arr[N - 1][0]);

	for (int i = 0; i < N; ++i) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
