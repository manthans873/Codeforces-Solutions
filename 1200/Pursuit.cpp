// prob link: https://codeforces.com/contest/1530/problem/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 2e5;
ll a[N];
ll b[N];
ll n;

bool ok(int m){
    ll A=0,B=0;
    ll take = m - m/4;
    ll hdr = min(m-n, take);
    A += hdr*100;
    ll i = n-1;
    ll j = n - min(n,take);
    while(i >= j){
        B += b[i];
        i--;
    } 
    take -= hdr;
    i = n-1;
    while(take > 0){
        A += a[i];
        take--;
        i--;
    }
    // cout<<A<<" "<<B<<"\n";
    return (A >= B);
}
void solve(){  
    cin>>n;
    for(ll i=0; i<n; ++i) cin>>a[i];
    for(ll i=0; i<n; ++i) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    // cout<<ok(7)<<"\n";
    ll l=n, r=1e8, m;
    while(l+1 < r){
        m = l + (r-l)/2;
        if(ok(m)){
            r = m;
        }else{
            l = m;
        }
    }
    // cout<<l<<" "<<r<<"\n";
    if(ok(l)) cout<<l-n<<"\n";
    else cout<<r-n<<"\n";

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
