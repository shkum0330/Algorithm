#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    std::fill_n(dp,1001,1);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    for(int i=1;i<n;i++) {
        for (int j = 0; j < i; j++) {
            if(arr[i]<arr[j]) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int max=dp[0];
    for (int i = 1; i < n; ++i) {
        if(max<dp[i]) max=dp[i];
    }

    cout<<max<<'\n';
}
