#include <iostream>
using namespace std;

int T = 0, n = 0, ans = 0;

int main() {
	cin >> T;

	for(int tc = 1; tc <= T; ++tc) {
		cin >> n;
		int A = 0;
		ans = n;
		int max = 0;
		for(int i = 0; i < n; ++i) {
			cin >> A;
			ans += A;
			if(A > max) {
				max = A;
			}
		}
		printf("#%d %d\n", tc, ans+max);
	}

	return 0;
}
