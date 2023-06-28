#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 121;

char s[NN][NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf(" %c", s[i] + j);
		}
	}
	
	vector<string> row;
	for(int i = n; i--; ) {
		row.push_back("");
		for(int j = m; j--; ) {
			row.back() += s[i][j];
		}
	}
	sort(row.begin(), row.end());
	string row_s;
	for(int i = row.size(); i--; ) row_s += row[i];
	
	vector<string> col;
	for(int j = m; j--; ) {
		col.push_back("");
		for(int i = 0; i < n; i++) {
			col.back() += s[i][j];
		}
	}
	sort(col.begin(), col.end());
	string col_s;
	for(int i = col.size(); i--; ) col_s += col[i];
	
	string ans = max(row_s, col_s);
	for(int i = 0; i < ans.size(); i++) if(ans[i] != '0') {
		for(int j = i; j < ans.size(); j++) putchar(ans[j]);
		puts("");
		return 0;
	}
	puts("0");
	return 0;
}
