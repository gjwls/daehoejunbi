#include <iostream>
#include <algorithm>
using namespace std;
double dp[7][7][7][1001];
int cal(int a, int b, int c);
double solv(int a, int b, int c, int left);

void main() {
	int n;
	cin >> n;
	double sum = 0;
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i < 7; i++)
		for(int j = 1; j<7; j++)
			for (int k = 1; k < 7; k++) {
				sum += solv(i, j, k, n - 3);
			}
	printf("%.8lf", sum / (6*6*6));
	
	
}

int cal(int a, int b, int c) {
	if (a == b && b == c) return a * 1000 + 10000;
	else if (a == b || b == c || a == c) return (a == b ? a : c) * 100 + 1000;
	else {
		int rt = max(a, b);
		rt = max(rt, c);
		return rt * 100;
	}
}

double solv(int a, int b, int c, int left) {
	double cur = cal(a, b, c);	

	if (left == 0)
		return cur;
	
	double& ret = dp[a][b][c][left];
	if (ret > 0)
		return ret;
	double more = 0;
	for (int i = 1; i < 7; i++)
		more += solv(b, c, i, left - 1);
	return ret = max(cur, more / 6);
}