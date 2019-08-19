#include<stdio.h>
#define PI 3.14159265359
int r;

int main() {
	scanf("%d", &r);

	printf("%.6f\n", r*r*PI);
	printf("%d.000000\n", 2*r*r);

	return 0;
}
