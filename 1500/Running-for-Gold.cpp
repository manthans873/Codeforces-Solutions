// prob link: https://codeforces.com/contest/1552/problem/B

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+2;

bool operator < (vector<int>& a, vector<int>& b){
    int cnt = 0;
    for(int i=0; i<5; ++i){
        if(a[i] < b[i]) cnt++;
    }
    // cout<<cnt<<"\n";
    return (cnt >= 3);
}
void solve(){
    int n;
    cin>>n;

    vector<vector<int>> mat(n, vector<int>(5));
    for(int i=0; i<n; ++i){
        for(int j=0; j<5; ++j){
            cin>>mat[i][j];
        }
    }
    int idx = 0; 
    for(int i=1; i<n; ++i){
        // cout<<"i: "<<i<<" ";
        if(mat[i] < mat[idx]){
            idx = i;
        }
    }
    for(int i=0; i<n; ++i){
        if(i == idx) continue;
        if(mat[i] < mat[idx]){
            cout<<-1<<"\n";
            return ;
        }
    }
    cout<<idx+1<<"\n";

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
