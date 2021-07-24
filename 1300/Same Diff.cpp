// prob link: https://codeforces.com/problemset/problem/1520/D

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(ll n){
    ll res = 0;
    res = (n)*(n-1)/2;
    return res;
}

// aj-ai = j-i
// aj-j = ai-i

void solve() {
    ll n, x, res=0;
    cin>>n;
    unordered_map<ll, ll>mp;
    for(ll i=0; i<n; ++i){
        cin>>x;
        x-=i;
        mp[x]++;
    }
    for(auto it: mp){
        res += f(it.second);
    }
    cout<<res<<"\n";

}
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}
