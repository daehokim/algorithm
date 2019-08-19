#include<stdio.h>
int a, b, c;
void isRight(int a, int b, int c) {
	if (a*a + b * b == c * c) {
		printf("right\n");
	}
	else {
		printf("wrong\n");
	}
}
int main() {

	while (true) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) break;
		if (a > b && a > c) {
			isRight(b, c, a);
		}
		else if (b > a && b > c) {
			isRight(a, c, b);
		}
		else {
			isRight(a, b, c);
		}
	}
	return 0;
}
