#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
double** cal(int** map, int n);
double dist(int x, int y, int a, int b);

int main() {
	int n;
	cin >> n;
	int** map = new int* [n];
	for (int i = 0; i < n; i++)
	{
		map[i] = new int[2];
		cin >> map[i][0] >> map[i][1];
	}
	double** arr = cal(map, n);
	int* res = new int[n];
	double max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > max) { 
				res[i] = j; 
				max = arr[i][j];
			}
		}
		max = 0;
	}
	double min = 10000000;
	int index_a, index_b;
	for (int i = 0; i < n; i++)
		if (min > arr[i][res[i]]) {
			index_a = i;
			index_b = res[i];
			min = arr[i][res[i]];
		}
	if (arr[index_a][index_b] == min) cout << map[index_a][0]  << " " << map[index_a][1];
	else cout << map[index_b][0] << " " << map[index_b][1];
}

double** cal(int** map, int n) {
	double** ret = new double* [n];
	for (int i = 0; i < n; i++)
		ret[i] = new double[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret[i][j] = dist(map[i][0], map[i][1], map[j][0], map[j][1]);
		}
	}
	return ret;
}

double dist(int x, int y, int a, int b) {
	return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}

