// prob link: https://codeforces.com/problemset/problem/1418/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int N = 2e5+2;

int n;
int a[N];
int dp[N][2];

int fill(int idx, int turn){
    if(idx >= n) return 0;

    // memoization
    if(dp[idx][turn] != -1) return dp[idx][turn];

    if(turn){
        if(idx == n-1){
            dp[idx][turn] = (a[idx] == 1) ? 1 : 0;
        }
        else if(idx < n-1 && a[idx] == 1 && a[idx+1] == 0){
            dp[idx][turn] = min(1 + fill(idx+1, turn^1), 1 + fill(idx+2, turn^1));
            
        }
        else if(idx < n-1 && a[idx] == 1 && a[idx+1] == 1){
            dp[idx][turn] = min(1 + fill(idx+1, turn^1) , 2 + fill(idx+2, turn^1));  

        }
        else if(idx < n-1 && a[idx] == 0 && a[idx+1] == 0){
            dp[idx][turn] = min(fill(idx+1, turn^1) , fill(idx+2, turn^1));

        }
        else{
            dp[idx][turn] = min(fill(idx+1, turn^1), 1 + fill(idx+2, turn^1));

        } 
    }else{
        dp[idx][turn] = min(fill(idx+1, turn^1), fill(idx+2, turn^1));
    }
    return dp[idx][turn];

}
void solve(){
    cin>>n;
    for(int i=0; i<n; ++i) cin>>a[i];

    memset(dp, -1, sizeof(dp));
    fill(0, 1);
    cout<<dp[0][1]<<"\n";


}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }


	return 0;
}
