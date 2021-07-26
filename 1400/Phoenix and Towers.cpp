// prob link: https://codeforces.com/problemset/problem/1515/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n,m,x;
    cin>>n>>m>>x;
    vector<ll>a(n);
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    set<pair<ll,ll>>st;  //height, idx
    for(int i=1;i<=m; ++i){
        st.insert({0,i});
    }
    cout<<"YES\n";                                          
    for(int i=0; i<n; ++i){
        pair<ll,ll> p = *st.begin();
        st.erase(p);
        st.insert({p.first+a[i], p.second});
        cout<<p.second<<" ";
    }
    cout<<"\n";
    
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}
