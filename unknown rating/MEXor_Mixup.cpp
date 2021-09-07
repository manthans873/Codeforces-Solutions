// prob link: https://codeforces.com/contest/1567/problem/B


#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
const int N = 2e5+5;

// from GFG
int xoro(int n){
    if(n%4 == 0) return n;
    if(n%4 == 1) return 1;
    if(n%4 == 2) return n+1;
    return 0;
}
int solve(){
    int a,b;
    cin>>a>>b;
    int x=0;
    x = xoro(a-1);
    int y = x^b;
    if(x == b) return a;
    if(y == a) return a+2;
    return a+1;
        
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
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }

    return 0;
}
