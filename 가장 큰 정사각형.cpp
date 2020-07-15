#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool func(int n, int m, int c);
int map[1000][1000];
int ret = 0;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			if (map[i][j] == 1)
				ret = 1;
	
	for (int i = 1;;i++)
	{
		if (!func(n, m, i))
			break;
	}
	cout << ret * ret;
}

bool func(int n, int m, int c) {
	bool tf = false;
	for(int i = c; i < n; i++)
		for(int j = c; j < m; j++)
			if (map[i][j] >= c && map[i - 1][j] >= c && map[i][j - 1] >= c && map[i - 1][j - 1] >= c)
			{
				map[i][j] = c+1;
				tf = true;
				ret = c + 1;
			}
	return tf;
}