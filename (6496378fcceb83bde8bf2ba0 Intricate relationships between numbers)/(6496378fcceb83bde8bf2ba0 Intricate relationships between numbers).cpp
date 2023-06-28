#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 4040404;

bool flag[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, ans = 0; scanf("%d", &n);
	for(int i = n; i; i--) if(!flag[i << 1] && !flag[i << 2]) {
		flag[i] = 1, ans++;
	}
	printf("%d\n", ans);
	return 0;
}
