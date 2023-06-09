#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
vector<int> count_btn;
queue<int> count_list;

int main()
{
	cin >> F >> S >> G >> U >> D;

	count_btn.resize(F + 1);
	fill(count_btn.begin(), count_btn.end(), 1234567890);
	count_btn[S] = 0;

	count_list.push(S);
	int up = 0, down = 0, now = 0;
	while (count_list.empty() == false)
	{
		now = count_list.front();
		count_list.pop();
		up = now + U;
		if (up <= F && up != now && count_btn[up] > count_btn[now] + 1)
		{
			count_list.push(up);
			count_btn[up] = count_btn[now] + 1;
		}

		down = now - D;
		if (down >= 1 && down != now && count_btn[down] > count_btn[now] + 1)
		{
			count_list.push(down);
			count_btn[down] = count_btn[now] + 1;
		}
	} 

	if (count_btn[G] == 1234567890)
	{
		cout << "use the stairs" << endl;
	}
	else
	{
		cout << count_btn[G] << endl;
	}

	return 0;
}
