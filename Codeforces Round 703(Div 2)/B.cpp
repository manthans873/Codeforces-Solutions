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

// link https://codeforces.com/contest/1486/problem/B
ll btween(vector<ll>a,int n){
    sort(a.begin(),a.end());
    if(n%2==1) return 1;    // - - - 3
    return a[n/2] - a[n/2 - 1] + 1;  // - - - - 4
}
void solve(){
    int n;
    cin>>n;
    vector<ll>x(n);
    vector<ll>y(n);
    for(int i=0;i<n;++i) cin>>x[i]>>y[i];
    // xC1 * yC1
    cout<<btween(x,n)*btween(y,n)<<"\n";
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