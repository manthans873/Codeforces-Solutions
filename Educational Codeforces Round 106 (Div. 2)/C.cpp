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

// prob link: https://codeforces.com/contest/1499/problem/C
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    ll odsum=a[1], evsum=a[0], od=a[1], ev=a[0], ans=0, odnum=1, evnum=1;
    ans = (a[0] + a[1])*n;
    for(int i=2;i<n;i++){
        if(i%2==0){
            evsum+=a[i];
            evnum++;
            if(a[i] < ev) ev = a[i];
            ans = min(ans, (n - evnum + 1)*ev + evsum - ev + (n - odnum + 1)*od + odsum - od);
        }
        else{
            odsum+=a[i];
            odnum++;
            if(a[i] < od) od = a[i];
            ans = min(ans, (n - evnum + 1)*ev + evsum - ev + (n - odnum + 1)*od + odsum - od);
        }
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
