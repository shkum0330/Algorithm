#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

string s;
bool p[2501][2501];
int dp[2501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>s;
    int n=s.size();
    dp[0]=1;
    for (int i = 1; i < n; ++i) {
        dp[i]=INF;
    }

    for (int i = 0; i < n; ++i) {
        p[i][i]=true;
    }

    for (int i = 0; i < n-1; ++i) {
        if(s[i] == s[i+1]) p[i][i+1]=true;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 2; j < n; j++) {
            if (s[i] == s[j] && p[i + 1][j - 1]) {
                p[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(p[j][i]) dp[i]=min(dp[i],dp[j-1]+1);
        }
    }

    cout<<dp[n-1]<<'\n';
}
