#include <iostream>
#include <map>
using namespace std;

int N, tmp, M;
map<int, int> card;

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &tmp);
		map<int, int>::iterator it = card.find(tmp);
		if (it == card.end()) {
			card.insert(make_pair(tmp, 1));
		}
		else {
			++it->second;
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &tmp);
		map<int, int>::iterator it = card.find(tmp);
		if (it == card.end()) {
			printf("0 ");
		}
		else {
			printf("%d ", it->second);
		}
	}
	printf("\n");
	return 0;
}
