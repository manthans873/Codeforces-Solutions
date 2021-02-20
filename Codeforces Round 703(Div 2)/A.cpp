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

// prob link: https://codeforces.com/contest/1486/problem/A
void solve(){
    int n,flg=1;
    cin>>n;
    ll sm=0;
    vector<ll>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    // let this case {0 0 100} (correct output -> NO)
    for(int i=0;i<n;++i){
        sm+=a[i];
        if(sm < i*(i+1)/2){
            flg=0;
            break;
        }
    }
    if(flg) cout<<"YES\n";
    else cout<<"NO\n";
}
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
        solve();
    }
    return 0;
}