#include <iostream>
#include <vector>
using namespace std;

struct Cloud
{
	int r;
	int c;
	Cloud(int _r = 0, int _c = 0) : r(_r), c(_c) {}
};
int dir[9][2] = { {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1 ,1},  {1, 0}, {1, -1} };
int N, M, A[50][50], d, s;
bool previous_cloud[50][50];
int ans;
vector<Cloud> cloud_list;

void MoveCloud();
void CopuBug();
void MakeCloud();

int main()
{
	cin >> N >> M;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			cin >> A[r][c];
			previous_cloud[r][c] = false;
		}
	}

	cloud_list.reserve(N*N);

	// 처음 구름
	cloud_list.push_back(Cloud(N - 2, 0));
	cloud_list.push_back(Cloud(N - 2, 1));
	cloud_list.push_back(Cloud(N - 1, 0));
	cloud_list.push_back(Cloud(N - 1, 1));

	for (int m = 0; m < M; ++m)
	{
		// 명령어 입력
		d = 0;
		s = 0;
		cin >> d >> s;
		s %= N; // N 초과는 반복임

		MoveCloud();
		CopuBug();
		MakeCloud();
	}

	// 결과
	ans = 0;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			ans += A[r][c];
		}
	}

	cout << ans << endl;
	return 0;
}

void MoveCloud()
{
	// 1. 구름 이동
	for (int i = 0, size = cloud_list.size(); i < size; ++i)
	{
		Cloud &temp_cloud = cloud_list[i];
		
		temp_cloud.r += dir[d][0] * s;
		temp_cloud.c += dir[d][1] * s;

		if (temp_cloud.r < 0)
		{
			temp_cloud.r += N;
		}
		if (temp_cloud.r >= N)
		{
			temp_cloud.r -= N;
		}
		if (temp_cloud.c < 0)
		{
			temp_cloud.c += N;
		}
		if (temp_cloud.c >= N)
		{
			temp_cloud.c -= N;
		}
	}
}

void CopuBug()
{
	// 2. 비가 내림, 구름 위치 체크
	for (int i = 0, size = cloud_list.size(); i < size; ++i)
	{
		Cloud temp_cloud = cloud_list[i];

		++A[temp_cloud.r][temp_cloud.c];
		previous_cloud[temp_cloud.r][temp_cloud.c] = true;
	}

	// 4. 물 복사 버그
	for (int i = 0, size = cloud_list.size(); i < size; ++i)
	{
		Cloud temp_cloud = cloud_list[i];

		for (int d = 2; d < 9; d += 2)
		{
			int r = temp_cloud.r + dir[d][0];
			int c = temp_cloud.c + dir[d][1];
			if (r >= 0 && r < N && c >= 0 && c < N && A[r][c] > 0)
			{
				++A[temp_cloud.r][temp_cloud.c];
			}
		}
	}

	// 3. 구름 삭제
	cloud_list.clear();
}

void MakeCloud()
{
	// 5. 구름 생성
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (A[r][c] >= 2 && previous_cloud[r][c] == false)
			{
				cloud_list.push_back(Cloud(r, c));
				A[r][c] -= 2;
			}
			else
			{
				// 이전 구름 위치 초기화
				previous_cloud[r][c] = false;
			}
		}
	}

}
