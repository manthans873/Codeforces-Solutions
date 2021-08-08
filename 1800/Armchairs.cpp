
// prob link: https://codeforces.com/contest/1525/problem/D

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, x;
const int N = 5001;
int dp[N][N]; 

int rec(int i, int j, vector<int>& occ, vector<int>& uocc){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == occ.size()) return 0;
    if(j == uocc.size()) return 1e9;

    dp[i][j] = min(rec(i, j+1, occ, uocc), rec(i+1, j+1, occ, uocc) + abs(occ[i]-uocc[j]));
    return dp[i][j];
    // min(notTaken, taken);
}

void solve(){
    cin>>n;
    vector<int> occ, uocc;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; ++i){
        cin>>x;
        if(x == 0) uocc.push_back(i);
        else occ.push_back(i);
    }
    cout<<rec(0, 0, occ, uocc)<<"\n";
}


int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
