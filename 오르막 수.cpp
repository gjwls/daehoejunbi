#include <iostream>
#include <string.h>
#include <algorithm>
long long cal(int p, int left);
using namespace std;
long long sum[10][1001];

int main() {
	int n;
	cin >> n;
	cout << cal(0, n) % 10007;
	return 0;
}

long long cal(int p, int left) {
	long long sum_t = 0;
	if (left == 0)
		return 1;
	if (sum[p][left] != 0)
		return sum[p][left];
	for(int i = p; i < 10; i++)
	{
		sum_t += cal(i, left - 1)% 10007;
	}
	return sum[p][left] = sum_t;
}