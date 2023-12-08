#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair<int,int> pii;
typedef long long ll;

int n;
int board[101][101];
long long dp[101][101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>board[i][j];
        }
    }
    dp[0][0]=1;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if(dp[i][j]==0 || (i==n-1 && j==n-1)) continue;
            int d=i+board[i][j];
            int r=j+board[i][j];
            if(d<n) dp[d][j] += dp[i][j];
            if(r<n) dp[i][r] += dp[i][j];
        }
    }
    cout<<dp[n-1][n-1]<<'\n';
}