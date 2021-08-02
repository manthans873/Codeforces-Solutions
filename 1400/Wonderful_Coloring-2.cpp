// prob link: https://codeforces.com/contest/1551/problem/B2


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 2e5+2;


void solve(){  
    ll n,k,x;
    cin>>n>>k;
    vector<ll>a(n, 0);
    vector<ll>b(n);
    map<ll, vector<ll>>mp;
    for(ll i=0; i<n; ++i){
        cin>>x;
        mp[x].push_back(i);
        b[i] = x;
    }
    ll color=0, s=0, m=0;
    for(auto elm: mp){
        vector<ll> vec = elm.second;
        ll sz = vec.size();
        if(sz > k){
            m++;
            for(int i=0; i<k; ++i){
                a[vec[i]] = color+1;
                color = (color+1)%k;
            }
        }else{
            s+=sz;
            for(int i=0; i<sz; ++i){
                a[vec[i]] = color+1;
                color = (color+1)%k;
            }
        }
    }
    ll tt = m + s/k;
    // cout<<tt<<"\n";
    map<ll,ll> f;
    for(ll i=0; i<n; ++i){
        if(a[i] != 0) f[a[i]]++;
        if(f[a[i]] > tt){
            cout<<0<<" ";
        }else{
            cout<<a[i]<<" ";
        }
    }  

    cout<<"\n";
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
