#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int sum[50001];
int func(int n, int now, int c, int left);
int dp[50001][3];
int main() {
	int n, c;
	cin >> n;
	for (int i = 1; i < n + 1; i++)
	{
		int a;
		cin >> a;
			sum[i] += sum[i - 1] + a;
	}
	cin >> c;
	cout << func(n, 1, c, 3);
	return 0;
}

int func(int n, int now,int c, int left) {
	if (left == 0)
		return 0;
	if (n - now + 1 == c * left) {
		dp[now][left] = sum[n] - sum[now - 1];
		return sum[n] - sum[now - 1];
	}
	if (n - now + 1 < c * left)
		return 0;
	if (dp[now][left] != 0) {
		return dp[now][left];
	}
	else
	{
		dp[now][left] = max(func(n, now + 1, c, left), func(n, now + c, c, left - 1) + sum[now + c - 1] - sum[now - 1]);
		return dp[now][left];
	}
}