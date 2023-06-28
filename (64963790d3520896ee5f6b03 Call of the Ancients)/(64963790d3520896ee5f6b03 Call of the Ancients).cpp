#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

using DO = double;

DO x = 3.43221, y = 8.13214;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int ans = 0;
	for(DO i = 5; i < 99; i += 10) {
		for(DO j = 5; j < 99; j += 10) {
			printf("? %lf %lf\n", i, j);
			fflush(stdout);
			int x; scanf("%d", &x);
			if(x) ans++;
		}
	}
	if(ans > 1) puts("! 20");
	else puts("! 10");
	fflush(stdout);
	return 0;
}