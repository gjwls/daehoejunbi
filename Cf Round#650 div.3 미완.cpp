#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <set>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
queue<int> ret;
bool f(int st, int en);
int map[600000];
int main() {
	int t;
	cin >> t;
	int temp;
	int rt;
	for (int i = 0; i < t; i++) {
		int n, k;
		int sum = 0;
		cin >> n >> k;
		for (int j = 200000; j < 200000 + n; j++)
			scanf("%1d", &map[j]);
		for (int j = 200000; j < 200000 + n; j++)
		{
			if (f(j - k, j + k)) {
				sum++;
				map[j] = 1;
				j += k;
			}
		}
		ret.push(sum);
		for (int i = 0; i < n; i++)
			map[200000 + i] = 0;
	}
	while (!ret.empty()) {
		cout << ret.front() << endl;
		ret.pop();
	}
	
}

bool f(int st, int en) {
	for (int i = st; i < en + 1;i++) 
		if (map[i] == 1)
			return false;
	return true;
}