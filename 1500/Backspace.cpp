// prob link: https://codeforces.com/contest/1553/problem/D

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve(){  
    string s,t;
    cin>>s>>t;
    int S = s.size(), T = t.size();
    int i=S-1, j=T-1;
    while(j >= 0){
        while(s[i] != t[j] && i >= 0){
            i-=2;
        }
        if(i < 0){
            cout<<"NO\n";
            return;
        }
        i--;
        j--;
    }
    cout<<"YES\n";

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
