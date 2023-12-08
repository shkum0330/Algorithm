#include <bits/stdc++.h>
using namespace std;

long long dp[91];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    dp[1]=1; dp[2]=1; dp[3]=2;
    for(int i=4;i<=n;i++){
        int idx=i-2;
        while(idx>=1){
            dp[i] += dp[idx];
            idx--;
        }
        dp[i] += 1;
    }
    cout<<dp[n]<<'\n';

}
