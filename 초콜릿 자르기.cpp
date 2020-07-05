#include <iostream>
#include <string.h>

using namespace std;
#define MIN(a,b) (a<b? a:b)
int cal(int row, int col);
int dp[1001][1001];


int main() {
	memset(dp, -1, sizeof(dp));
	int row, col;
	cin >> row >> col;
	cout << cal(row, col) << endl;
	
	return 0;
}

int cal(int row, int col) {
	int ret = 100000;
	if (row == 1 || col == 1)
		return (row == 1 ? col : row);
	if (row == 0 || col == 0)
		return 0;
	int max = MIN(row, col);
	for (int i = 1; i <= max; i++) {
		ret = MIN(MIN((dp[row - i][col] != -1 ? dp[row - i][col] : cal(row - i, col)) + (dp[i][col - i] != -1 ? dp[i][col - i] : cal(i, col - i)) + 1, (dp[row][col - i] != -1 ? dp[row][col - i] : cal(row, col - i)) + (dp[row - i][i] != -1 ? dp[row - i][i] : cal(row - i, i)) + 1), ret);
	}
	dp[row][col] = ret;
	dp[col][row] = ret;
	return ret;
}