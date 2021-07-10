
// prob link: https://codeforces.com/problemset/problem/1538/F

using namespace std;
typedef long long ll;

void solve(){
    ll l,r;
    cin>>l>>r;
    ll ans=0, digit = 1;
    while(r/digit){
        ans += r/digit - l/digit;
        digit*=10;
    }
    cout<<ans<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
