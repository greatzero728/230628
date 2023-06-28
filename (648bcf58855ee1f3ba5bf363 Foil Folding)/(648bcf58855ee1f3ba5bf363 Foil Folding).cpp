#include <bits/stdc++.h>

using namespace std;

#define Error(x) cerr<<#x<<" = "<<x<<endl;

int n , m , K , X;
vector< string > str , rev;
vector< vector< int > > a , sum;

bool can(int i , int j , int mid){
	if(i + K -1 >= n) return false;
	if(j + mid - 1 >= m) return false;
	int val = sum[i][j+mid-1] - (j == 0 ? 0 : sum[i][j-1]);
	return val <= X;
}

int solve(){
//	int n = s.size() , m = s[0].length();
	if(K > n) return 0;
	a.clear() , sum.clear();
	a.resize(n) , sum.resize(n);
	for(int i = 0 ; i < n ; i++ ) a[i].resize(m) , sum[i].resize(m);
	for(int i = 0 ; i <= n-K ; i++ ){
		for(int j = 0 ; j < m ; j++ ){
			if(i == 0){
				for(int k = 0 ; k < K ; k++ ) a[0][j] += (str[k][j] == 'X');
			}else{
				a[i][j] = a[i-1][j] - (str[i-1][j] == 'X') + (str[i+K-1][j] == 'X');
			}
		}
	}
	for(int i = n-K+1; i < n ; i++ ){
		for(int j = 0 ; j < m ; j++ ) a[i][j] = 0;
	}
	
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < m ; j++ ){
			if(!j) sum[i][j] = a[i][j];
			else sum[i][j] = sum[i][j-1] + a[i][j];
		}
	}
//	for(int i = 0 ; i < n ; i++ ){
//		for(int j= 0 ; j < m ; j++ ) cout<<a[i][j]<<" \n"[j == m-1];
//	}
//	for(int i = 0 ; i < n ; i++ ){
//		for(int j= 0 ; j < m ; j++ ) cout<<sum[i][j]<<" \n"[j == m-1];
//	}
	int ret = 0;
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < m ; j++ ){
			int lo = 0 , hi = m+1;
			while(lo + 1 < hi){
				int mid = (lo + hi) >> 1;
				if(can(i , j , mid)) lo = mid;
				else hi = mid;
			}
			ret = max(ret , lo);
		}
	}
	return ret;
}
int main(){
//	freopen("in.in" , "r" , stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>K>>X;
	
	str.resize(n);
	for(int i = 0 ; i < n ; i++ ) cin>>str[i];
	int ans = solve();
	rev.resize(m);
	for(int i = 0 ; i < m ; i++ ){
		string s = "";
		for(int j = 0 ; j < n ; j++ ) s += str[j][i];
		rev[i] = s;
	}
	swap(n , m);
	str = rev;
	ans = max(ans , solve());
	cout<<ans<<endl;
}