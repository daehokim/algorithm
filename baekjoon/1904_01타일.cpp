#include<stdio.h>
#define P 15746
int n, a, b, tmp; 
int main() {
	scanf("%d", &n);
	a = 1;
	b = 1;
	for (int i = 2; i <= n; ++i) {
		tmp = b;
		b = (b + a)%P;
		a = tmp;
	}
	printf("%d", b);
	return 0;
}
