// prob link: https://codeforces.com/problemset/problem/1520/E

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve() {
    ll n,res=0;
    string s;
    cin>>n>>s;
    vector<ll>pos;
    for(ll i=0; i<n; ++i){
        if(s[i] == '*') pos.push_back(i);
    }
    ll len = pos.size();
    if(len == n || len == 0){
        cout<<0<<"\n";
        return;
    }
    ll mid = len/2, temp = pos[mid];
    // left ones
    for(ll i=mid-1; i>=0; --i){
        res += pos[mid]-pos[i]-1;
        pos[mid]--;
    }
    // right ones
    pos[mid] = temp;
    for(ll i=mid+1; i<len; ++i){
        res += pos[i]-pos[mid]-1;
        pos[mid]++;
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
