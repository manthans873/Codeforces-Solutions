// prob link: https://codeforces.com/contest/1557/problem/C
// Moamen and XOR

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
/*

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

MAIN POINT OF THIS QUESTION

WHEN CALLING pwr(a, b*c)
DON'T CALL IT pwr(a, (b*c)%mod) -> it will give wrong ans 

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

*/
ll mod = 1e9+7;

ll mul(ll a, ll b){
    ll res = ((a%mod)*(b%mod))%mod;
    return res;
}
ll add(ll a, ll b){
    ll res = ((a%mod)+(b%mod))%mod;
    return res;
}
ll pwr(ll a, ll b)
{
    ll res = 1;   
    while (b > 0){
        if (b & 1){
            res = mul(res,a);
        }
        b = b>>1; 
        a = mul(a,a);
    }
    return res;
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
    
    
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> dp(k+1, 0);
        dp[0] = 1;
        for(ll kk=1; kk<=k; ++kk){
            if(n%2 == 0){
                ll x = dp[kk-1];
                ll y = pwr(2,n-1)-1;
                ll z = pwr(2, (kk-1)*n);
                dp[kk] = add(mul(x,y),z);
            }
            else{
                ll x = dp[kk-1];
                ll y = pwr(2,n-1);
                dp[kk] = add(mul(x,y),x);
            }
        }
        cout<<dp[k]<<"\n";
    }

    return 0;
}
