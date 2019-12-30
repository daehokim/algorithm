#include <iostream>
#include <vector>
using namespace std;

int N, S, input, ans, len;
vector<int> seq;

void permutation(int idx, int sum)
{
	if (idx == N)
	{
		if (sum == S)
		{
			++ans;
		}
		return;
	}
	permutation(idx + 1, sum + seq[idx]);
	permutation(idx + 1, sum);
}

int main()
{
	cin >> N >> S;
	ans = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		seq.push_back(input);
	}
	len = seq.size();
	permutation(0, 0);
	if (S == 0)
	{
		--ans;
	}
	cout << ans << endl;
	return 0;
}
