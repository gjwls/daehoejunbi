#include <bits/stdc++.h>
using namespace std;
deque<int> dq[2];
int dp[500][500];
void f(int n);
int arr[500][500];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];
	}
	dp[0][0] = arr[0][0];
	f(t);
	sort(dp[t - 1], dp[t - 1] + t);
	cout << dp[t - 1][t-1];
	return 0;
}

void f(int n) {
	for (int k = 1; k < n; k++) {
		for (int j = 0; j <= k;j++) {
			if (j == 0)
			{
				dp[k][j] = dp[k - 1][j] + arr[k][j];
				continue;
			}
			else if (j == k) {
				dp[k][j] = dp[k - 1][j - 1] + arr[k][j];
				continue;
			}
			dp[k][j] = max(dp[k - 1][j], dp[k - 1][j - 1]) + arr[k][j];
		}
	}
}