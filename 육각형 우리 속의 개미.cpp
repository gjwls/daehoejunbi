#include <iostream>
#include <string.h>
#include <math.h>
#include <set>
using namespace std;

int main() {
	int n;
		
	cin >> n;
	double** map = new double* [n];
	for (int i = 0; i < n;i++) 
		map[i] = new double[2];
	memset(map, 0, sizeof(map));
	map[1][0] = 0;
	map[1][1] = 1;
	int past[2];
	int recpath[2][2];
	past[0] = 0;
	past[1] = 1;

	for (int i = 0; i < n; i++) {
		
	}
	
	
	return 0;
}

double** path(int past[2]) {
	double ret[2][2];
	if (past[0] == 0 && past[1] == 1)
	{
		ret[0][0] = -sqrt(3) / 2;
		ret[0][1] = 0.5;
		ret[1][0] = sqrt(3) / 2;
		ret[1][1] = 0.5;
	}
	else if (past[0] == sqrt(3) / 2 && past[1] == 0.5)
	{
		ret[0][0] = 0;
		ret[0][1] = 1;
		ret[1][0] = sqrt(3) / 2;
		ret[1][1] = -0.5;
	}
	else if (past[0] == sqrt(3) / 2 && past[1] == -0.5)
	{
		ret[0][0] = 0;
		ret[0][1] = -1;
		ret[1][0] = sqrt(3) / 2;
		ret[1][1] = 0.5;
	}
	else if (past[0] == 0 && past[1] == -1)
	{
		ret[0][0] = -sqrt(3) / 2;
		ret[0][1] = -0.5;
		ret[1][0] = sqrt(3) / 2;
		ret[1][1] = -0.5;
	}
	else if (past[0] == -sqrt(3) / 2 && past[1] == -0.5)
	{
		ret[0][0] = -sqrt(3) / 2;
		ret[0][1] = 0.5;
		ret[1][0] = 0;
		ret[1][1] = -1;
	}
	else
	{
		ret[0][0] = 0;
		ret[0][1] = 1;
		ret[1][0] = -sqrt(3) / 2;
		ret[1][1] = -0.5;
	}
}

