#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int tc[20001];
int arr[20001][2];

int main() {
	int t, n, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		int* kar = new int[k];
		for (int i = 0; i < k; i++)
			kar[i] = 0;
		int max = 1;
		for (int j = 0; j < n; j++){
			cin >> arr[j][0];
			arr[j][1] = k - arr[j][0] % k;
			if (arr[j][1] == k)
				arr[j][1] = 0;
			kar[arr[j][1]]++;
		}
		for (int j = 2; j < k; j++) {
			if (kar[max] <= kar[j])
				max = j;
		}
		tc[i] = kar[max] * k + max - k;
	}
	for (int i = 0; i < t; i++)
		cout << tc[i] + 1 << endl;
}
