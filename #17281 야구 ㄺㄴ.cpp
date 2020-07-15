#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <set>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int simul(int last, int ining);
int count(int n);
int arr[50][9];
int sunse[9];

int main() {
	int t;
	int ret = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (i == j) continue;
			for (int k = 1; k < 9; k++) {
				if (i == k || j == k) continue;
				for (int q = 1; q < 9; q++) {
					if (i == q || j == q || k == q) continue;
					for (int w = 1; w < 9; w++) {
						if (i == w || j == w || k == w|| q == w) continue;
						for (int e = 1; e < 9; e++) {
							if (i == e || j == e || k == e || q == e || w == e) continue;
							for (int r = 1; r < 9; r++) {
								if (i == r || j == r || k == r || q == r || w == r || e == r) continue;
								for (int y = 1; y < 9; y++) {
									if (i == y || j == y || k == y || q == y || w == y || e == y || r == y) continue;
									sunse[0] = i;
									sunse[1] = j;
									sunse[2] = k;
									sunse[3] = 0;
									sunse[4] = q;
									sunse[5] = w;
									sunse[6] = e;
									sunse[7] = r;
									sunse[8] = y;
									ret = max(ret, simul(0, t));
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ret;
}

int simul(int last, int ining) {
	int out = 0;
	int ru = 0;
	int sum = 0;
	for (int j = 0; j < ining; j++) {
		for (int i = last;out < 3;i++) {
			i %= 9;
			if (arr[j][sunse[i]] == 0)
				out++;
			else if (arr[j][sunse[i]] == 1)
				ru = (ru << 1) + 1;
			else if (arr[j][sunse[i]] == 2)
				ru = (ru << 2) + 2;
			else if (arr[j][sunse[i]] == 3)
				ru = (ru << 3) + 4;
			else
			{
				sum += count(ru) + 1;
				ru = 0;
			}
			if (ru >= 8) {
				int b = ru >> 3;
				sum += count(b);
				b = b << 3;
				ru -= b;
			}
			if (out == 3)
				last = i + 1;
		}
		out = 0;
		ru = 0;
	}
	return sum;
}

int count(int n) {
	int i = 0;
	for (;n != 0;i++) {
		n &= (n - 1);
	}
	return i;
}
