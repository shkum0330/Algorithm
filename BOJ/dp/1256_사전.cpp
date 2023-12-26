#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int dp[401][201];

string solve(int n, int m, int k) {

    if (n == 0){
        string tmp="";
        for (int i = 0; i < m; ++i) {
            tmp += 'z';
        }
        return tmp;
    }
    if (m == 0){
        string tmp="";
        for (int i = 0; i < n; ++i) {
            tmp += 'a';
        }
        return tmp;
    }

    if (k <= dp[n + m - 1][n - 1]){
        return "a" + solve(n - 1, m, k);
    }
    else {
        return "z" + solve(n, m - 1, k - dp[n + m - 1][n - 1]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,k; cin>>n>>m>>k;

    for (int i = 0; i <= n+m; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 2; i <= n+m; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = min(dp[i - 1][j - 1] + dp[i - 1][j], INF);
        }
    }

    if (dp[n + m][n] < k){
        cout << -1 << '\n';
    }
       
    else{
        cout << solve(n, m, k) << '\n';
    }
        
}
