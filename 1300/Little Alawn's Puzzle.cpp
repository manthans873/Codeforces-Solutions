// prob link: https://codeforces.com/contest/1534/problem/Cgit

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


const int N = 1e6 + 7;
const ll MOD = 1e9+7;
int n;
int x[N];
int pr[N];
bool vis[N];

void solve() {
    cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>x[i];
        x[i]--;
    }
	for (int i = 0; i < n; i++) {
		int inp;
        cin>>inp;
        pr[x[i]] = inp-1;
	}
    vector<int> adj[n+1];
    for(int i=0; i<n; ++i){
        vis[i] = false;
    }
	ll res=1;
    for(int i=0; i<n; ++i){
        if(!vis[i] && pr[i] != i){
            int idx = i;
            while(!vis[idx]){
                vis[idx] = true;
                idx = pr[idx];
            }
            res = (2*res)%MOD;
        }
    }
    cout<<res<<"\n";
}
 
int main()
{
 
	int t;
	cin>>t;
	while(t--) solve();
 
	return 0;
}