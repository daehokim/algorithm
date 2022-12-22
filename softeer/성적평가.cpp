#include<stdio.h>
#include<iostream>
#include<set>
#include<vector>
#include<map>

using namespace std;

int N;
vector<vector<int>> score;
multiset<int> temp;
map<int, int> ranking;

int main(int argc, char** argv)
{
	cin >> N;
	score.resize(4);
	score[3].resize(N);
	for(int t = 0; t < 3; ++t)
	{
		score[t].resize(N);
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &score[t][i]);
			score[3][i] += score[t][i]; // 최종 스코어 업데이트
			temp.insert(score[t][i]);
		}


		//<점수-등수> map에 복사
		auto it = temp.rbegin();
		int rank = 1;
		for(auto end = temp.rend(); it != end; ++it)
		{
			ranking.insert({*it, rank});
			++rank;
		}

		// 결과 출력
		for(int i = 0; i < N; ++i)
		{
			printf("%d ", ranking.find(score[t][i])->second);
		}
		printf("\n");

		temp.clear();
		ranking.clear();
	}

	// 최종 스코어 정렬
	for(int i = 0; i < N; ++i)
	{
		temp.insert(score[3][i]);
	}

	auto it = temp.rbegin();
	int rank = 1;
	for(auto end = temp.rend(); it != end; ++it)
	{
		ranking.insert({*it, rank});
		++rank;
	}

	for(int i = 0; i < N; ++i)
	{
		printf("%d ", ranking.find(score[3][i])->second);
	}
	printf("\n");
	
	return 0;
}
