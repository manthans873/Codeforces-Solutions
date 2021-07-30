// prob link: https://codeforces.com/contest/1554/problem/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 2e5+2;
ll a,b;

// void brute(ll a, ll b){
//     for(int i=0; i<=b; ++i){
//         cout<<(a^i)<<" ";
//     }
//     cout<<"\n";
//     for(int i=b+1; i<=20; ++i){
//         cout<<(a^i)<<" ";
//     }
//     cout<<"\n";
// }
void solve(){  
    cin>>a>>b;
    // brute(a, b);
    ll res=0;
    b++;
    for(ll i=31; i>=0; i--){
        bool b1 = ((1ll<<i)&a);
        bool b2 = ((1ll<<i)&b);
        // cout<<b1<<" "<<b2<<"\n";
        if(!b1 && b2){
            res += (1ll<<i);
        }
        else if(b1 && !b2){
            // res += 0
            // as we need to minimise the val of res
            break;
        }
    }
    cout<<res<<"\n";

}

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
