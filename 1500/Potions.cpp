// prob link: https://codeforces.com/problemset/problem/1526/C1

// O(N*N)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


const int N = 2004;
const ll MOD = 1e9+7;
int n, t, x;
ll dp[N+1][N+1];

void solve() {
    cin>>n;
    memset(dp,192,sizeof(dp));
    dp[0][0] = 0;
    for(int i=1; i<=n; ++i){
        dp[i][0] = 0;
    }
    for(int i=1; i<=n; ++i){
        cin >> x;
        for(int j=1; j<=n; ++j){
            if(x + dp[i-1][j-1] >= 0){
                dp[i][j] = max(x + dp[i-1][j-1], 0 + dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int j=n; j>=0; --j){
        if(dp[n][j] >= 0){
            cout<<j<<"\n";
            return;
        }
    }
}
 
int main(){
    solve();
 
	return 0;
}


//Hard Version	O(N)
// prob link: https://codeforces.com/contest/1534/problem/C2

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


const int N = 2004;
const ll MOD = 1e9+7;
ll n, t, x;


void solve() {
    cin>>n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll summ=0, cnt=0;
    for(ll i=0; i<n; ++i){
        cin>>x;
        if(summ + x >= 0){
            summ += x;
            cnt++;
            if(x < 0) pq.push(x);
        }
        else{
            if(pq.empty()) continue;
            else{
                ll top = pq.top();
                if(top < x){
                    summ = summ-top+x;
                    pq.push(x);
                    pq.pop();
                }
            }
        }
    }
    cout<<cnt<<"\n";
}
 
int main(){
    solve();
 
	return 0;
}
