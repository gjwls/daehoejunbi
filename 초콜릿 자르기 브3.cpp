#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
int cal(int* cost, int n);

using namespace std;
int main() {
	int n;
	cin >> n;
	int* cost = new int[n+1];
	for (int i = 1; i < n+1; i++)
		cin >> cost[i];
	cout << cal(cost, n);
	
	
}

int cal(int* cost, int n) {
	int* ret = new int[n+1];
	for (int i = 0; i < n + 1; i++)
	{
		ret[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n + 1; j++)
		{
			if (i + j <= n)
				ret[i + j] = max(ret[i + j], ret[i] + cost[j]);
		}
	}
	return ret[n];
}