#include <bits/stdc++.h>
using namespace std;

int dp[12];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    dp[1]=1; dp[2]=2; dp[3]=4;
    while (t--){
        int n; cin>>n;
        for(int i=4;i<=n;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        cout<<dp[n]<<'\n';
    }

}
