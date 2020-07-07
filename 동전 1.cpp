#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int coin[101];
	int dp[10001];
	for (int i = 0; i < 10001; i++)
		dp[i] = 0;
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j < k+1; j++)
			dp[j] += dp[j - coin[i]];
	}
	cout << dp[k];
}