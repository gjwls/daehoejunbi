#include <iostream>
#include <string>
using namespace std;
string trans(int** map, int a, int b, int c, int d);

int main() {
	int n;
	cin >> n;
	int** map = new int*[n];
	for (int i = 0; i < n; i++)
		map[i] = new int[n];
	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++)
			map[i][j] = s.at(j) - 48;
	}
	cout << trans(map, 0, n, 0, n) << endl;
}

string trans(int** map, int a, int b, int c, int d) {
	int n = 0;
	string ret = "";
	for (int i = a; i < b; i++)
		for (int j = c; j < d; j++)
			if (map[i][j] == 1)
				n++;
	if (n == 0)
		return "0";
	else if (n == (b - a) * (d - c))
		return "1";
	ret = ret + "(";
	ret = ret + trans(map, a, (a + b) / 2, c, (c + d) / 2);
	ret = ret + trans(map, a, (a + b) / 2, (c + d) / 2, d);
	ret = ret + trans(map, (a + b) / 2, b, c, (c + d) / 2);
	ret = ret + trans(map, (a + b) / 2, b, (c + d) / 2, d);
	ret = ret + ")";
	return ret;
}