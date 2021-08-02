// prob link: https://codeforces.com/contest/1555/problem/D

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int n, m;

vector<string> perm = {
    "abc", "acb", "bca", "bac", "cab", "cba"
};
void compare(vector<int> &vec, int idx){
    string fin = perm[idx];
    for(int i=0; i<n; ++i){
        if(s[i] != fin[i%3]){
            vec[i+1]++;
        }
    }
    for(int i=2; i<n+1; ++i){
        vec[i] += vec[i-1];
    }
}
void solve(){
    int l, r; 
    cin>>n>>m;
    cin>>s;

    vector<vector<int>> dp(6, vector<int> (n+1, 0));
    for(int i=0; i<6; ++i){
        compare(dp[i], i);
    }
    // for(int i=0; i<6; ++i){
    //     for(int j=0; j<n+1; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    while(m--){
        cin>>l>>r;
        cout<<min({
            dp[0][r]-dp[0][l-1],
            dp[1][r]-dp[1][l-1],
            dp[2][r]-dp[2][l-1],
            dp[3][r]-dp[3][l-1],
            dp[4][r]-dp[4][l-1],
            dp[5][r]-dp[5][l-1],
        })<<"\n";

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
