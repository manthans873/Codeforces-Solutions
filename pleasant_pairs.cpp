
// prob link: https://codeforces.com/contest/1541/problem/B

void solve(){
    ll n, cnt=0;
    cin>>n;
    vector<ll>a(n+1);
    for(ll i=1; i<=n; ++i){
        cin>>a[i];
    }
    for(ll i=1; i<=n; ++i){
        for(ll j=a[i]-i; j<=n; j+=a[i]){
            if(j < 1) continue;
            if(j>i && a[i]*a[j] == i + j){
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}
/*
    a[i]*a[j] = i+j
    for fixed i -> a[i]*a[j] - i = j
    let a[i] = 3 and i = 1
    then j = 3*a[j] - 1
    j = 2,5,8,11....
    so j += a[i] is the suitable condition
    and also j>i and j>=1
*/
// Time complx: O(nlogn)

