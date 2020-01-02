#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> q;

int main()
{
	cin >> N >> K;
	int visit[100001] = { 0, };
	q.push(N);
	visit[N] = 1;
	while (!q.empty())
	{
		N = q.front();
		q.pop();
		if (N == K)
		{
			cout << visit[N] - 1 << endl;
			return 0;
		}
		if (N * 2 <= 100000 && visit[N * 2] == 0) {
			visit[N * 2] = visit[N] + 1;
			q.push(N * 2);
		}
		if (N + 1 <= 100000 && visit[N + 1] == 0)
		{
			visit[N + 1] = visit[N] + 1;
			q.push(N + 1);
		}
		if (N - 1 >= 0 && visit[N - 1] == 0)
		{
			visit[N - 1] = visit[N] + 1;
			q.push(N - 1);
		}
	}
}
