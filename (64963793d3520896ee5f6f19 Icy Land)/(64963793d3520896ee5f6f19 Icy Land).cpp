#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 505;

char s[NN][NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	
	int ans = 0;
	for(int i = 2; i < n; i++) {
		for(int j = 2; j < m; j++) {
			if(s[i][j] == '.') ans++;
		}
	}
	
	if(n > 2 && m > 2) {
		bool ok = 0;
		for(int i = 2; i < m; i++) {
			if(s[1][i] == '#') ok = 1;
			if(s[n][i] == '#') ok = 1;
		}
		for(int i = 2; i < n; i++) {
			if(s[i][1] == '#') ok = 1;
			if(s[i][m] == '#') ok = 1;
		}
		if(!ok) ans++;
	}
	else if(n <= 2) {
		for(int i = 2; i < m; i++) if(s[1][i] == '.' && s[n][i] == '.') {
			ans++;
		}
	}
	else {
		for(int i = 2; i < n; i++) if(s[i][1] == '.' && s[i][m] == '.') {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
