#include <iostream>

#define max(a,b) (a > b ? a : b)
using namespace std;
void wi(int** arr, int index, int lim);

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	int maxd = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxd = max(maxd, arr[i]);
	}
	int* ans_arr = new int[maxd+1];
	for (int i = 0; i < maxd + 1; i++) {
		ans_arr[i] = 0;
	}
	ans_arr[0] = 1;
	for (int i = 0; i < maxd; i++){
		wi(&ans_arr, i, maxd);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", ans_arr[arr[i]]);
}

void wi(int** arr, int index, int lim) {
	if (index + 3 <= lim)
	{
		(*arr)[index + 3] += (*arr)[index];
	}
	if (index + 2 <= lim)
	{
		(*arr)[index + 2] += (*arr)[index];
	}
	if (index + 1 <= lim)
	{
		(*arr)[index + 1] += (*arr)[index];
	}
}

