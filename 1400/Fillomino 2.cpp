// prob link: https://codeforces.com/contest/1517/problem/C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int step;

void dfs(int i, int j, int num, vector<vector<int>>& mat){
    int n = mat.size();
    if(i >= n || j < 0 || step == 0) return;
    if(i != j && mat[i][j] != 0) return;
    step--;
    mat[i][j] = num;
    dfs(i+1, j, num, mat);
    dfs(i, j-1, num, mat);
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>>mat(n, vector<int>(n, 0));
    for(int i=0; i<n; ++i){
        cin>>mat[i][i];
    }
    for(int i=n-1; i>=0; --i){
        step = mat[i][i];
        dfs(i,i,mat[i][i],mat);
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<=i; ++j){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
        
}
 
int main(){
    solve();
	return 0;
}
