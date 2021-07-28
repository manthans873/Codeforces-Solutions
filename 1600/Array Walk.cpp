// prob link: https://codeforces.com/problemset/problem/1389/B

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int N = 1e5+2;

ll a[N];
ll dp[N][7];
ll rec(ll idx, ll z, ll k, ll n){
    if(k == 0 || idx < 0 || idx >= n || z < 0) return 0; 
    if(dp[idx][z] != -1) return dp[idx][z];

    dp[idx][z] = max(rec(idx+1, z, k-1, n) + a[idx], rec(idx-1, z-1, k-1, n) + a[idx]);
    return dp[idx][z];
    
}
void solve(){  
    ll n,k,z;
    cin>>n>>k>>z;
    for(ll i=0; i<n; ++i)
        cin>>a[i];

    memset(dp, -1, sizeof(dp));
    cout<<rec(0, z, k+1, n) <<"\n";
}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }


	return 0;
}
