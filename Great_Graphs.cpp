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
#include <stack>

using std::cin;
using std::pair;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::unordered_map;
using std::vector;

typedef long long ll;

void solve(){
    ll n, ans=0;
    cin>>n;
    vector<ll>d(n);
    vector<ll>summ(n, 0);
    for(ll i=0; i<n; ++i) cin>>d[i];
    sort(d.begin(), d.end());
    summ[0] = d[0];
    for(ll i=1; i<n; ++i){
        summ[i] = summ[i-1] + d[i];
    }
    for(ll i=n-1; i>=1; --i){
        ans += summ[i-1] - i*d[i];
    }
    ans += d[n-1];
    cout<<ans<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
