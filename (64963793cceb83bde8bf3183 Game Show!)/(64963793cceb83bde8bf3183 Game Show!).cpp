#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int sum = 100, n, x, ans = sum;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		sum += x;
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}
