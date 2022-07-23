#include <bits/stdc++.h>
using namespace std;

int n;
int arr[11];
int res[11];
bool visited[11];

int blankCnt(int idx){
    int cnt=0;
    for(int i=1;i<idx;i++) if(visited[i]==0) cnt++;
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) {
        int cnt=0;

        for(int j=arr[i]+1;j<=n;j++){
            if(!visited[j] && arr[i]==blankCnt(j)) {
                res[j]=i;
                visited[j]= true;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<' ';
    cout<<'\n';
}