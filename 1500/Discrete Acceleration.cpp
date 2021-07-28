// prob link: https://codeforces.com/problemset/problem/1408/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int N = 2e5+2;

void solve(){
    cout.precision(16);
    ll n,l,val;
    cin>>n>>l;
    double a[n];
    for(ll i=0; i<n; ++i){
        cin>>a[i];
    }

    double x=0, y=l, xx=1, yy=1;
    double t=0;
    int i=0, j=n-1;
    while(i <= j){
        double dx = a[i]-x;
        double dy = y-a[j];
        double tx = dx/xx, ty = dy/yy;
        if(tx < ty){
            x += dx;
            y -= yy*tx;
            xx++;
            t += tx;
            i++;
        }else{
            y -= dy;
            x += xx*ty;
            yy++;
            t += ty;
            j--;
        }
    }
    t += (y-x)/(xx+yy);
    cout<<t<<"\n";

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
