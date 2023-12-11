#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m;
ll res;
char board[3001][3001];
ll dp[3001][3001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j] == board[i - 1][j - 1] && board[i][j] != board[i - 1][j] && board[i][j] != board[i][j - 1]) {
                dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] });
                dp[i][j]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res += dp[i][j];
        }
    }
    cout << res << '\n';

}
