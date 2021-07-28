// prob link: https://codeforces.com/problemset/problem/1398/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int N = 1e5+2;


void solve(){  
    ll n, x;
    string s;
    cin>>n>>s;

    map<ll,ll>dp;
    dp[0] = 1;
    ll sm=0, res=0;
    for(ll i=0; i<n; ++i){
        x = s[i]-'0';
        x--;
        sm += x;
        res += dp[sm];
        dp[sm]++;
    }
    cout<<res<<"\n";

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
