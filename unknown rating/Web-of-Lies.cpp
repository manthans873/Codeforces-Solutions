// prob link: https://codeforces.com/contest/1549/problem/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+2;

int n,m,cnt=0;
vector<int> adj[N];
int frd[N];

void dfs(int node){
    for(int cld: adj[node]){
        if(cld > node) frd[node]++;
    }
}

void solve(){
    int u,v,q,cdt;
    cin>>n>>m;
    for(int i=0; i<m; ++i){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    for(int i=1; i<=n; ++i){
        dfs(i);
    }
    for(int i=1; i<=n; ++i){
        if(frd[i] == 0)
            cnt++;
    }

    // cout<<cnt<<"\n";
    cin>>q;
    while(q--){
        cin>>cdt;
        if(cdt == 1){
            cin>>u>>v;     
            if(frd[min(u,v)] == 0) cnt--;                                   
            frd[min(u,v)]++;
        }
        else if(cdt == 2){
            cin>>u>>v;
            frd[min(u,v)]--; 
            if(frd[min(u,v)] == 0) cnt++;
        }
        else{
            cout<<cnt<<"\n";
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

	return 0;
}
