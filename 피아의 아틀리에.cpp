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
int num[10][4][4];
char color[10][4][4];
int gj[5][5];
char gj_c[5][5];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> num[i][j][k];
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> color[i][j][k];
			}
		}
	}
	
}

void hapchigi(int* a[4][4], char* c[4][4], int pos) {
	if (pos == 1) {
		for(int i = 0; i < 4;i++)
			for (int j = 0; j < 4;j++)
			{
				gj[i][j] += *a[i][j];
				if (gj[i][j] < 0)
					gj[i][j] = 0;
				else if (gj[i][j] > 9)
					gj[i][j] = 0;
				if(gj_c[i][j] == "W")
			}
	}
	else if (pos == 2) {

	}
	else if (pos == 3) {

	}
	else {

	}
}

void turn(int *a[4][4]) {
	int ary[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ary[i][j] = *a[i][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			*a[3 - j][i] = ary[i][j];
}

void turn(char* a[4][4]) {
	char ary[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ary[i][j] = *a[i][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			*a[3 - j][i] = ary[i][j];
}