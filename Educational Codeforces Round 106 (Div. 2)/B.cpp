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

// prob link: https://codeforces.com/contest/1499/problem/B
void solve(){
    string s;
    int p0 = -1, p1 = -1;
    cin>>s;
    for(int i=1;i<s.length();++i){
        if(s[i] == '1' && s[i-1] == '1'){
            p1 = i;
            break;
        }
    }
    for(int i=s.length()-1;i>=1;--i){
        if(s[i] == '0' && s[i-1] == '0'){
            p0 = i;
            break;
        }
    }
    if(p1 == -1 || p0 == -1){
        cout<<"YES\n";
        return;
    }
    if(p1 < p0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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
