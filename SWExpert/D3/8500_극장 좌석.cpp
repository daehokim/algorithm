#include <iostream>
using namespace std;

int T = 0, n = 0, ans = 0, max = 0;
int* A = NULL;

int main() {
	cin >> T;

	for(int tc = 1; tc <= T; ++tc) {
		cin >> n;
		A = new int[n];
		ans = n;
		max = 0;
		for(int i = 0; i < n; ++i) {
			cin >> A[i];
			ans += A[i];
			if(A[i] > max) {
				max = A[i];
			}
		}
		cout << "#" << tc << " " << ans+max << endl;
		delete[] A;
	}

	return 0;
}
