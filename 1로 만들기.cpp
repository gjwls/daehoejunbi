#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define min(a,b) (a < b ? a : b)
using namespace std;
void wi(int** arr, int index, int lim);

int main() {
	int n;
	cin >> n;
	int* arr = new int[n+1];
	for (int i = 0; i < n + 1; i++)
		arr[i] = 0;
	for (int i = 1; i < n ; i++)
	{
		wi(&arr, i, n);
	}
	printf("%d", arr[n]);

}

void wi(int** arr, int index, int lim) {
	if (index * 3 <= lim) {
		if ((*arr)[index * 3] != 0)
			(*arr)[index * 3] = min((*arr)[index * 3], (*arr)[index] + 1);
		else
			(*arr)[index * 3] = (*arr)[index] + 1;
	}
	if (index * 2 <= lim) {
		if ((*arr)[index * 2] != 0)
			(*arr)[index * 2] = min((*arr)[index * 2], (*arr)[index] + 1);
		else
			(*arr)[index * 2] = (*arr)[index] + 1;
	}
	if (index + 1 <= lim)
	{
		if ((*arr)[index + 1] != 0)
			(*arr)[index + 1] = min((*arr)[index + 1], (*arr)[index] + 1);
		else
			(*arr)[index + 1] = (*arr)[index] + 1;
	}
}

