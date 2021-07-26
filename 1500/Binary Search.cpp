// prob link: https://codeforces.com/problemset/problem/1436/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll f(ll n){
    ll res=1;
    for(ll i=2; i<=n; ++i){
        res = (res*i)%MOD;
    }
    return res;
}
void solve() {
    ll n,x,pos;
    cin>>n>>x>>pos;
    ll l=0, r=n, m;
    ll s=0, g=0;
    while(l < r){
        m = (l+r)/2;
        if(m <= pos){
            s++;
            l = m+1;
        }else{
            g++;
            r = m;
        }
    }
    // cout<<g<<" "<<s<<"\n";
    s--;        // as we include x also in s
    ll res = 1;
    ll G=n-x, S=x-1;
    for(ll i=0; i<g; ++i){
        // if(G <= 0) break;
        res = (res*G)%MOD;
        G--;
    }
    for(ll i=0; i<s; ++i){
        // if(S <= 0) break;
        res = (res*S)%MOD;
        S--;
    }
    res = (res*f(n-g-s-1))%MOD;     // n-g-s-1 this -1 as one pos is fixed i.e of x
    cout<<res<<"\n";

}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }

	return 0;
}
