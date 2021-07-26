// prob link: https://codeforces.com/contest/1506/problem/D

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;


void solve(){
    ll n, val;
    cin>>n;
    map<ll,ll>mp;           // 1 <= ai <= 1e9 these are very large hence unordered_map gives TLE 
    for(ll i=0; i<n; ++i){
        cin>>val;
        mp[val]++;
    }
    priority_queue<pair<ll,ll>>pq;
    for(auto elm: mp){
        pq.push({elm.second, elm.first});
    }
    ll cnt=0;
    while(pq.size() >= 2){
        auto p = pq.top();
        pq.pop();
        auto q = pq.top();
        pq.pop();
        p.first--;
        if(p.first > 0){
            pq.push(p);
        }
        q.first--;
        if(q.first > 0){
            pq.push(q);
        }
        cnt++;
    }
    cout<<n-2*cnt<<"\n";
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }

	return 0;
}
