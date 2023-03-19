#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair<int,int> pii;
typedef long long ll;

int n;
int box[1001];
int dp[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>box[i];
        dp[i]=1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(box[i]>box[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int res=-1;
    for (int i = 0; i < n; ++i) {
        res=max(res,dp[i]);
    }
    cout<<res<<'\n';
}