#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int L, C;
char input;
bool chk[26];
vector<char> alpha;
set<string> ans;

int vowelCnt(string _tar)
{
	int cnt = 0;
	if (_tar.find('a') != string::npos) ++cnt;
	if (_tar.find('e') != string::npos) ++cnt;
	if (_tar.find('i') != string::npos) ++cnt;
	if (_tar.find('o') != string::npos) ++cnt;
	if (_tar.find('u') != string::npos) ++cnt;
	return cnt;
}

void perm(int _idx, string _tmp)
{
	if (_tmp.length() == L)
	{
		int cnt = vowelCnt(_tmp);
		if (cnt >= 1 && cnt <= L - 2 && ans.end() == ans.find(_tmp))
		{
			ans.insert(_tmp);
		}
		return;
	}
	for (int i = _idx; i < C; ++i)
	{
		perm(i + 1, _tmp);
		_tmp.push_back(alpha[i]);
		perm(i + 1, _tmp);
	}
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; ++i)
	{
		cin >> input;
		chk[input - 'a'] = true;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (chk[i])
		{
			alpha.push_back(i + 'a');
		}
	}
	perm(0, "");

	string answer;
	for (set<string>::iterator iter = ans.begin(), iterEnd = ans.end(); iter != iterEnd; ++iter)
	{
		answer.append(*iter).append("\n");
	}
	cout << answer;

	return 0;
}
