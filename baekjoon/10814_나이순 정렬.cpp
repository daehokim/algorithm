#include<stdio.h>

int n, **point, **sorted;
char **name;
void mergeSort(int, int);
void merge(int, int, int);

int main() {
	scanf("%d", &n);
	point = new int*[n];
	sorted = new int*[n];
	name = new char*[n];
	for (int i = 0; i < n; ++i) {
		point[i] = new int[2];
		name[i] = new char[102];
		scanf("%d %s", &point[i][1], name[i]);
		point[i][0] = i;
		
	}
	mergeSort(0, n - 1);
	for (int i = 0; i < n; ++i) {
		printf("%d %s\n", point[i][1], name[point[i][0]]);
	}
	return 0;
}

void mergeSort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end) {
	int l = start;
	int r = mid + 1;
	int index = start;
	while (l <= mid && r <= end) {
		if (point[l][1] < point[r][1]) sorted[index++] = point[l++];
		else if (point[l][1] > point[r][1]) sorted[index++] = point[r++];
		else {
			if (point[l][0] < point[r][0]) sorted[index++] = point[l++];
			else  sorted[index++] = point[r++];
		}
	}
	if (l <= mid) {
		for (int i = l; i <= mid; ++i) {
			sorted[index++] = point[i];
		}
	}
	else {
		for (int i = r; i <= end; ++i) {
			sorted[index++] = point[i];
		}
	}

	for (int i = start; i <= end; ++i) {
		point[i] = sorted[i];
	}
}
