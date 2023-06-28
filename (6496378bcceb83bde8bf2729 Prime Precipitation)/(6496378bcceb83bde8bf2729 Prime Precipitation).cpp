#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 4040404;

int f[NN], dp[NN];

int calc(int n) {
	if(n == 1) return 0;
	int ans = 0, p = f[n];
	while(n % p == 0) n /= p, ans++;
	return ans + calc(n);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 2; i <= n; i++) if(!f[i]) {
		f[i] = i;
		if((INT)i * i > n) continue;
		for(int j = i * i; j <= n; j += i) f[j] = i;
	}
	
	INT ans = 0;
	for(int i = 2; i <= n; i++) {
		dp[i] = dp[i - calc(i)] + 1;
		ans += dp[i];
	}
	printf("%I64d\n", ans);
	return 0;
}
