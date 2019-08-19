#include<stdio.h>
int x1, y1, x2, y2, x3, y3;

int main() {
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	if (x1 == x2 && y1 == y3) printf("%d %d\n", x3, y2);
	else if(x1 == x3 && y1 == y2) printf("%d %d\n", x2, y3);
	else if(x2 == x3 && y2 == y1) printf("%d %d\n", x1, y3);
	else if(x2 == x1 && y2 == y3) printf("%d %d\n", x3, y1);
	else if(x3 == x1 && y3 == y2) printf("%d %d\n", x2, y1);
	else if(x3 == x2 && y3 == y1) printf("%d %d\n", x1, y2);

	return 0;
}
