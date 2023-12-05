#include <bits/stdc++.h>
using namespace std;

#define INF 1999999999
int sum[501],file[501],dp[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        for(int i=1;i<=n;i++){
            cin>>file[i];
            sum[i]=sum[i-1]+file[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                dp[j][i+j]=INF;
                for(int k=j;k<i+j;k++){
                    dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+sum[i+j]-sum[j-1]);
                }
            }
        }
        cout<<dp[1][n]<<'\n';
    }
}