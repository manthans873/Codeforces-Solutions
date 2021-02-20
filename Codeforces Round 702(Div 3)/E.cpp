#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <map>

using std::cout;  
using std::cin;
using std::string;
using std::vector;
using std::unordered_map;
using std::max;

typedef long long ll;
const ll IMAX = 1000000000000000000;
const ll IMIN = -100000000000000000;

// Prob link: https://codeforces.com/contest/1490/problem/E
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // for fast i/o (don't use scanf/printf)
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n),b(n);
        vector<std::pair<ll,ll>>pr;
        vector<ll>ans;
        for(ll i=0;i<n;++i){
            cin>>a[i];
            pr.push_back({a[i],i+1});
        }
        sort(a.begin(),a.end());
        b[0]=a[0];
        for(ll i=1;i<n;++i){
            b[i] = b[i-1] + a[i];
        }
        ll cnt=1;
        for(ll i=n-2;i>=0;--i){
            if(b[i] >= a[i+1]){
                cnt++;
            }
            else{
                break;
            }
        }
        sort(pr.begin(),pr.end());
        // cout<<cnt<<"\n";
        for(ll ct=0;ct<cnt;++ct){
            ans.push_back(pr[n-ct-1].second);
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for(ll elm : ans){
            cout<<elm<<" ";
        }
        cout<<"\n";
    }
    return 0;
}