#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

vector<int> vec[202020];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	while(n--) {
		int x, c; scanf("%d %d", &x, &c);
		vec[c].push_back(x);
	}
	for(int i = 1; i <= 200000; i++) {
		for(int j = 1; j < vec[i].size(); j++) if(vec[i][j - 1] > vec[i][j]) {
			puts("NO"); return 0;
		}
	}
	puts("YES");
	return 0;
}
