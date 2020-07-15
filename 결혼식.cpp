#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
bool dongi[500][500];
vector<int> v;
bool check[500];
int main() {
	int n, l;
	int a, b;
	int sum = 0;
	cin >> n >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> a >> b;
		dongi[a][b] = true;
		dongi[b][a] = true;
	}
	for (int i = 2; i < n + 1; i++) {
		if (dongi[1][i] == 1) {
			v.push_back(i);
			check[i] = true;
		}
	}
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end();++iter)
		for (int i = 1; i < n + 1; i++)
			if (dongi[*iter][i] == 1)
				check[i] = true;
	for (int i = 1; i < n + 1; i++)
		if (check[i] == true)
			sum++;
	cout << sum - 1;
}
