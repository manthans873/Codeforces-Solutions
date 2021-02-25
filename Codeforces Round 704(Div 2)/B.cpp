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
    int n, val;
    cin>>n;
    vector<int>vis(n + 1, false);
    std::stack<int>s;
    std::stack<int>t;
    std::stack<int>temp;
    for(int i=0;i<n;++i){
        cin>>val;
        s.push(val);
    }
    int num = n;
    while(!s.empty()){
        if(s.top() != num){
            temp.push(s.top());
            vis[s.top()] = true;
            s.pop();
        }
        else{
            t.push(s.top());
            vis[s.top()] = true;
            s.pop();
            while(!temp.empty()){
                t.push(temp.top());
                temp.pop();
            }
            while(vis[num]){
                num--;
            }
        }
    }
    vector<int>ans;
    while(!t.empty()){
        ans.push_back(t.top());
        t.pop();
    }
    reverse(ans.begin(),ans.end());
    for(int elm:ans){
        cout<<elm<<" ";
    }
    cout<<"\n";
    
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