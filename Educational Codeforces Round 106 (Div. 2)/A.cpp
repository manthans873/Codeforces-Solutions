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

// prob link: https://codeforces.com/contest/1499/problem/A
void solve(){
    int n,k1,k2,w,b;
    cin>>n>>k1>>k2>>w>>b;
    if(w+b > n){
        cout<<"NO\n";
        return;
    }
    if((k1 + k2)/2 >= w && (2*n - k1 - k2)/2 >= b){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}
int main(){
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