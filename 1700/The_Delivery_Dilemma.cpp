// prob link: https://codeforces.com/problemset/problem/1443/C
// The Delivery Dilemma

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

ll n;
ll a[N],b[N];

ll solve(){
    cin>>n;
    for(ll i=1; i<=n; ++i) b[i]=0;
    for(ll i=1; i<=n; ++i){
        cin>>a[i];
        b[i] += a[i]-1;
        for(ll j=i+2; j<=n && j<=a[i]+i; ++j){
            b[j]--;
        }
    }
    for(ll i=1; i<=n; ++i){
        if (b[i]<0){
            b[i+1] += b[i];
            b[i] = 0;
            // treansfer to next
            // 1 1 3 need 2 steps
            // -1 -1 2 -> 0 0 0
        }
    }
    // for(ll i=1; i<=n; ++i){
    //     cout<<b[i]<<" ";
    // }
    // cout<<"\n";
    ll res=0;
    for(ll i=1; i<=n; ++i){
        res+=b[i];
    }
    return res;
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
