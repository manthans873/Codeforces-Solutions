// prob link: https://codeforces.com/contest/1552/problem/D

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[11];
int n;
bool dfs(int idx, int x, bool flag){
    cout<<idx<<" "<<x<<"\n";
    if(idx >= n){
        return x == 0 && flag;
    }
    bool res = dfs(idx+1, x + a[idx], true);
    res |= dfs(idx+1, x-a[idx], true);
    res |= dfs(idx+1, x, flag);

    return res;
}

void solve(){
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    
    cout<<(dfs(0, 0, false) ? "YES\n" : "NO\n");

}

// 0 -3 2 10 2

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
