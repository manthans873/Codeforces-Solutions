// prob link: https://codeforces.com/contest/1555/problem/B

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve(){
    cout.precision(12);
    double W,H,x1,x2,y1,y2,w2,h2;
    cin>>W>>H>>x1>>y1>>x2>>y2;
    cin>>w2>>h2;
    double w1 = x2-x1, h1 = y2-y1;
    double res = 1e10;

    // cout<<h1<<" "<<h2<<"\n";
    if(h1+h2 <= H){
        // top
        double sft1 = max((double)0, h2-y1);
        // bottom
        double sft2 = max((double)0, y2-(H-h2));

        res = min(sft1, sft2);
    }
    if(w1+w2 <= W){
        // right
        double sft1 = max((double)0, w2-x1);
        // left
        double sft2 = max((double)0, x2-(W-w2));

        res = min({res, sft1, sft2});
    }
    cout<<(res == 1e10 ? -1 : res)<<"\n";

    
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
