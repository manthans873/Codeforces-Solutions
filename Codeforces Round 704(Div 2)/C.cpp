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

void solve(){
    int n,m,mx=-1;
    cin>>n>>m;
    vector<int>mxi(m),mni(m);
    string s,t;
    cin>>s>>t;
    for(int i=0; i<m; ++i){
        if(i == 0){
            for(int j=0; j<n; ++j){
                if(t[i] == s[j]){
                    mni[i] = j+1;
                    break;
                }
            }
        }
        else{
            for(int j=mni[i-1]; j<n; ++j){
                if(t[i] == s[j]){
                    mni[i] = j+1;
                    break;
                }
            }
        }
    }
    for(int i=m-1; i>=0; --i){
        if(i == m-1){
            for(int j=n-1; j>=0; --j){
                if(t[i] == s[j]){
                    mxi[i] = j+1;
                    break;
                }
            }
        }
        else{
            for(int j=mxi[i+1]-1-1; j>=0; --j){
                if(t[i] == s[j]){
                    mxi[i] = j+1;
                    break;
                }
            }
        }
    }
    for(int i=1;i<m;++i){
        mx = max(mx, mxi[i] - mni[i-1]);
    }
    cout<<mx<<"\n";
}

int main(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
