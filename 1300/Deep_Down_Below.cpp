// prob link: https://codeforces.com/contest/1561/problem/C


#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define rep(i,a,n) for(int i=0;i<n;++i)
const int N = 5e3+1;

ll isVal(ll m, vector<pair<ll,ll>>& a){
    int n = a.size();
    for(ll i=0; i<n; ++i){
        if(m>=a[i].first){
            m += a[i].second;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int solve(){
    ll n,k,x;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    for(ll i=0; i<n; ++i){
        cin>>k;
        ll mx = -1;
        for(ll j=0; j<k; ++j){
            cin>>x;
            mx = max(mx,x+1-j);
        }
        a[i] = {mx,k};
    }
    sort(a.begin(),a.end());
    ll l=0, r=1e9+5;
    while(l+1 < r){
        ll m = l+(r-l)/2;
        if(isVal(m,a)){
            r = m;
        }
        else{
            l = m;
        }
    }
    return r;
}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }

    return 0;
}
