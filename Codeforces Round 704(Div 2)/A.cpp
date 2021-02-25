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
using std::min;

typedef long long ll;
const ll IMAX = 1000000000000000000;
const ll IMIN = -100000000000000000;

ll maza(ll p,ll a){
    if(p <= a){
        return a - p;
    }
    else{
        ll mulp = (p/a);
        if(p%a != 0) mulp++;
        a = mulp*a;
        return a - p;
    }
}
void solve(){
    ll p, a, b, c, mn = IMAX;
    cin>>p>>a>>b>>c;
    mn = min(maza(p,a),mn);
    mn = min(maza(p,b),mn);
    mn = min(maza(p,c),mn);
    cout<<mn<<"\n";
}

int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    // cout<<maza(16,5);
    return 0;
}

// 100/99 = 1.000001