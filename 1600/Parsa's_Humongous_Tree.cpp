// prob link: https://codeforces.com/contest/1529/problem/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+2;

vector<int> adj[N];
bool vis[N];
ll dp[N][2];
ll val[N][2];

void dfs(ll num){
    vis[num] = true;
    for(ll cld: adj[num]){
        if(!vis[cld]){
            dfs(cld);
            dp[num][0] += max(abs(val[num][0] - val[cld][0]) + dp[cld][0], abs(val[num][0] - val[cld][1]) + dp[cld][1]);
            dp[num][1] += max(abs(val[num][1] - val[cld][0]) + dp[cld][0], abs(val[num][1] - val[cld][1]) + dp[cld][1]); 
        } 
    }
}
void solve(){
    ll n,l,r,u,v;
    cin>>n;
    // clear arrays
    for(ll i=1; i<=n; ++i){
        vis[i] = false;
        adj[i].clear();
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    for(ll i=1; i<=n; ++i){
        cin>>l>>r;
        val[i][0] = l;
        val[i][1] = r;
    }    
    for(ll i=0; i<n-1; ++i){
        cin>>u>>v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<max(dp[1][0], dp[1][1])<<"\n";
}


int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
 
    // for fast i/o
    // this code won't run in giiven time limits without this
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
