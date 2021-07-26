// prob link: https://codeforces.com/problemset/problem/1513/B

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
    ll n,mn=1e10;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0; i<n; ++i){
        cin>>a[i];
        mn = min(mn, a[i]);
    }
    ll ad=a[0];
    for(ll i=1;i<n; ++i){
        ad &= a[i];
    }
    if(mn != ad){
        cout<<0<<"\n";
        return;
    }
    ll cnt=0;
    for(ll i=0; i<n; ++i){
        if(mn == a[i]) cnt++;
    }

    // we need to fix the mn value at both the ends
    // eg if mn == 0    [0..........0] as for each i from 1 to n-1
    // the condition needs to be true
    // hence ans is number of arrangements 
    // hence ans = C(cnt,2)*2 * (n-2)!

    cnt = cnt%MOD;
    ll res = (cnt*(cnt-1))%MOD;
    res = (res * f(n-2))%MOD;
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
