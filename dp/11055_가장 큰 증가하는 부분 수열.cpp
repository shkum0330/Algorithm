#include <bits/stdc++.h>
using namespace std;

int a[1001];
int dp[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i]; dp[i]=a[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+a[i]);
        }
    }

    int max=dp[0];
    for (int i = 0; i < n; ++i) {
        if(max<dp[i]) max=dp[i];
    }
    cout<<max<<'\n';
}
