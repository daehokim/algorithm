#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

int H, K, R, ans;
queue<int> employee[1024][2];
vector<queue<int>> junior;
int junior_cnt;

int main(int argc, char** argv)
{
	cin >> H >> K >> R;

	junior_cnt = pow(2, H);
	junior.reserve(junior_cnt);
	int temp_task = 0;
	for (int i = 0; i < junior_cnt; ++i)
	{
		queue<int> temp_task_lisk;
		for (int j = 0; j < K; ++j)
		{
			scanf("%d", &temp_task);
			temp_task_lisk.push(temp_task);
		}
		junior.push_back(temp_task_lisk);
	}

	ans = 0;
	int date_idx = 0; // 날짜에 따른 처리하는 업무 인덱스
	for (int i = 1; i <= R; ++i)	// R일 동안 일 함.
	{
		date_idx = (i + 1) % 2;	// 0 : 홀수날, 1 : 짝수날

		// 부서장 업무 처리
		if (employee[1][date_idx].size() > 0)	// 내 업무가 남아 있는지
		{
			ans += employee[1][date_idx].front();
			employee[1][date_idx].pop();
		}
		// 부서장 밑에서부터 말단직원 위까지
		for (int employee_idx = 2; employee_idx < junior_cnt; ++employee_idx)
		{
			int senior_idx = employee_idx / 2;	// 상사
			int task_idx = employee_idx % 2; // 왼쪽 = 0, 오른쪽 = 1
			if (employee[employee_idx][date_idx].size() > 0) // 내 업무가 남아 있는지
			{
				employee[senior_idx][task_idx].push(employee[employee_idx][date_idx].front());
				employee[employee_idx][date_idx].pop();
			}
		}

		// 말단직원들 업무 처리
		for (int junior_idx = 0, employee_idx = junior_cnt; junior_idx < junior_cnt; ++junior_idx, ++employee_idx)
		{
			int senior_idx = employee_idx / 2; 	// 상사
			int task_idx = employee_idx % 2;	// 왼쪽 = 0, 오른쪽 = 1
			if (junior[junior_idx].size() > 0)	// 업무가 남아 있는지
			{
				employee[senior_idx][task_idx].push(junior[junior_idx].front());
				junior[junior_idx].pop();
			}
		}
	}

	cout << ans << endl;

	return 0;
}
