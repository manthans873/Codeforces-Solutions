
// prob link: https://codeforces.com/problemset/problem/1535/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve(){
    string s;
    cin>>s;
    ll n = s.size();
    vector<vector<ll>>dp(n, vector<ll>(2, 0));
    if(s[0] == '0'){
        dp[0][0] = 1;
    }else if(s[0] == '1'){
        dp[0][1] = 1;
    }else{
        dp[0][0] = 1;
        dp[0][1] = 1;
    }
    for(ll i=1; i<n; ++i){
        if(s[i] == '0'){
            dp[i][0] = dp[i-1][1] + 1ll;
        }else if(s[i] == '1'){
            dp[i][1] = dp[i-1][0] + 1ll;
        }else{
            dp[i][0] = dp[i-1][1] + 1ll;
            dp[i][1] = dp[i-1][0] + 1ll;
        }
    }
    ll res = 0;
    for(ll i=0; i<n; ++i){
        if(s[i] == '0'){
            res += dp[i][0];
        }else if(s[i] == '1'){
            res += dp[i][1];
        }else {
            res += max(dp[i][1], dp[i][0]);
        }
    }
    cout<<res<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0; 
}
