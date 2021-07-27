// prob link: https://codeforces.com/problemset/problem/1498/B

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

void solve(){
    ll n, W, x;
    cin>>n>>W;
    multiset<ll>ms;
    for(int i=0; i<n; ++i){
        cin>>x;
        ms.insert(x);
    }
    ll h=1, w=W;
    while(!ms.empty()){
        auto  itr = ms.upper_bound(w);
        if(itr == ms.begin()){
            w=W;
            h++;
        }else{
            itr--;
            w -= *itr;
            ms.erase(itr);
        }
    }
    cout<<h<<"\n";

}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }


	return 0;
}
