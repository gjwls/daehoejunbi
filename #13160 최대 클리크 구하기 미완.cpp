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
string cit[100];
vector<pair<int, int>> vpii;
vector<pair<int, vector<int>>> vpiv;
multiset<int> gap;
set<int> jj;
set<pair<int, int>> f(set<pair<int, int>> spii);
set<int> fin(pair<int, int> pairi, set<pair<int, int>> spii);

int main() {
	int n;
	cin >> n;

	set<pair<int, int>> spii;
	set<pair<int, int>> r;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		spii.insert(pair<int, int>(a, b));
	}
	r = f(spii);
	int j = 1;
	while (r.size() > 1) {
		r = f(r);
		j++;
	}
	pair<int, int> rpi = pair<int, int>(r.begin()->first, r.begin()->second);
	j--;
	cout << j << endl;
	set<int> res = fin(rpi,spii);
	set<int>::iterator iter3;
	for (iter3 = res.begin();iter3 != res.end();iter3++)
	{
		cout << *iter3 << " ";
	}
	return 0;
}

set<pair<int, int>> f(set<pair<int, int>> spii) {
	set<pair<int, int>> resu;
	set<pair<int, int>>::iterator iter1;
	set<pair<int, int>>::iterator iter2;
	set<pair<int, int>>::iterator iter3;
	iter3 = spii.end()--;
	for (iter1 = spii.begin();iter1 != spii.end();iter1++) {
		if (iter1 == iter3)
			break;
		for (iter2 = iter1++;iter2 != spii.end();iter2++) {

			if (iter1->second >= iter2->first&& iter1->first <= iter2->second) {
				resu.insert(pair<int, int>(iter2->first, min(iter1->second, iter2->second)));
			}

		}
	}
	return resu;
}

set<int> fin(pair<int, int> pairi,set<pair<int, int>> spii) {
	set<pair<int, int>>::iterator iter1;
	set<int> s;
	int i = 0;
	for (iter1 = spii.begin();iter1 != spii.end();iter1++) {
		if (iter1->second >= pairi.second && iter1->first <= pairi.first)
			s.insert(i);
		i++;
	}
	return s;
}