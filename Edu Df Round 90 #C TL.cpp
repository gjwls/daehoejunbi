#include <bits/stdc++.h>

using namespace std;
vector<int> vi;
vector<long long> vl;
pair<int, int> pii;
set<int> si;
set<pair<long long, int>> spll;
map<string, int> msi;
priority_queue<int> pq;
deque<int> dq;
multiset<int> ms;
vector <pair <int, int>> vp;
void f(int s, int e);
deque<char> dc;
long long all[2000001];
bool check[200001];

int main() {
	int t;
	cin >> t;
	string s;
	
	while (t--) {
		cin >> s;
		int minm = 0;
		int temp = 0;
		if (s.at(0) == 43) {
			minm = 1;
			temp = 1;
			vi.push_back(1);
		}
		else {
			minm = -1;
			temp = -1;
			vi.push_back(-1);
		}
		for (int i = 1; i < s.size();i++)
		{
			
			if (s.at(i) == 43) {
				temp++;
				vi.push_back(vi[i - 1]+1);
			}
			else {
				temp--;
				minm = min(temp, minm);
				vi.push_back(vi[i - 1] - 1);
			}
		}
		int count = 0;
		for (int j = 0; j < -minm;j++) {
			int temp = j;
			for (int i = 0; i < s.size();i++) {
				if (temp + vi[i] < 0) {
					count += i + 1;
					break;
				}
			}
		}
		cout << count + s.size() << endl;
		vi.clear();
	}
	
}