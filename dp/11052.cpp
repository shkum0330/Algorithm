#include <bits/stdc++.h>
using namespace std;

int p[10001];
int dp[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;

    for (int i = 1; i <= n; ++i) {
        cin>>p[i];
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= i ; ++j) {
            dp[i]=max(dp[i],dp[i-j]+p[j]);
        }
    }
    cout<<dp[n];
}
