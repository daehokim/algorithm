#include <stdio.h>

int T, n, cnt;

void calc(int now)
{
	if(now < 0) return;
	if(now == 0)
	{
		++cnt;
		return;
	}
	for(int i = 1; i <= 3; ++i)
	{
		calc(now-i);
	}
}
int main()
{
	scanf("%d", &T);
	for(int tc = 0; tc < T; ++tc)
	{
		cnt = 0;
		scanf("%d", &n);

		calc(n);

		printf("%d\n", cnt);
	}
	return 0;
}
