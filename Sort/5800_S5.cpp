#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int k; cin>>k;
    for(int i=1;i<=k;i++){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n,greater<>());

        int gap=0;
        for(int i=0;i<n-1;i++){
            gap=max(gap,arr[i]-arr[i+1]);
        }
        cout<<"Class "<<i<<'\n';
        cout<<"Max "<<arr[0]<<", Min "<<arr[n-1]<<", Largest gap "<<gap<<'\n';
    }
}