#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int m, n, cnt;
vector<vector<int>> tomato;
queue<int> q;

int main()
{
	scanf("%d %d", &m, &n);
	tomato.resize(n);
	for(int i = 0; i < n; ++i)
	{
		tomato[i].resize(m);
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", &tomato[i][j]);
			if(tomato[i][j] == 1)
			{
				q.push(i);
				q.push(j);
				tomato[i][j] = -1;
			}
		}
	}
	cnt = -1;
	while(!q.empty())
	{
		++cnt;
		for(int i = 0, size = q.size()/2; i < size; ++i)
		{
			int currX = q.front();
			q.pop();
			int currY = q.front();
			q.pop();
			for(int d = 0; d < 4; ++d)
			{
				int x = currX + dir[d][0];
				int y = currY + dir[d][1];
				if(x >= 0 && x < n && y >= 0 && y < m && tomato[x][y] == 0)
				{
					tomato[x][y] = -1;
					q.push(x);
					q.push(y);
				}
			}
		}
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(tomato[i][j] == 0)
			{
				cnt = -1;
				goto loop;
			}
		}
	}
	loop: printf("%d\n", cnt);
	return 0;
}
