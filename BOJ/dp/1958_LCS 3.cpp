#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

string s1,s2,s3;
int dp[101][101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>s1>>s2>>s3;

    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            for (int k = 1; k <= s3.size(); ++k) {
                if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]) dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else{
                    dp[i][j][k]=max({dp[i][j][k-1],dp[i][j-1][k],dp[i-1][j][k]});
                }
            }
        }
    }
    cout<<dp[s1.size()][s2.size()][s3.size()]<<'\n';
}
