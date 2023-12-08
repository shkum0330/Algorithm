#include <bits/stdc++.h>
using namespace std;

#define INF 1999999999
typedef pair<int,int> pii;
typedef long long ll;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int n;
long long dp[31];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    dp[0]=1; dp[2]=3;
    for (int i = 4; i <= n; i+=2) {
        dp[i]=dp[i-2] * dp[2];
        for (int j = i-4; j >= 0; j-=2) {
            dp[i] += dp[j]*2;
        }
    }
    cout<<dp[n]<<'\n';
}