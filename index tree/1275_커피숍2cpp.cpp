#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;

int n,m;
pll arr[1000001]; // 최솟값과 최댓값 순
ll treeN=1;
pll get(int start,int end){
    start += treeN-1;
    end += treeN-1;
    pll res;
    res.first=1999999999; res.second=-1;
    while(start<=end){
        if(start%2==1){
            res.first=min(res.first,arr[start].first);
            res.second=max(res.second,arr[start].second);
        }
        if(end%2==0){
            res.first=min(res.first,arr[end].first);
            res.second=max(res.second,arr[end].second);
        }
        start=(start+1)/2;
        end=(end-1)/2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    while (treeN<n) treeN *= 2;

    for (int i = 0; i < n; ++i) {
        int tmp; cin>>tmp;
        arr[treeN+i].first=tmp;
        arr[treeN+i].second=tmp;

    }
    for (int i = treeN-1; i >0 ; i--) {
        if(arr[i*2].first ==0 && arr[i*2+1].first ==0) arr[i].first=0;
        else if(arr[i*2].first ==0) arr[i].first=arr[i*2+1].first;
        else if(arr[i*2+1].first ==0) arr[i].first=arr[i*2].first;
        else  arr[i].first=min(arr[i*2].first,arr[i*2+1].first);
        arr[i].second=max(arr[i*2].second,arr[i*2+1].second);
    }

    for (int i = 0; i < m; ++i) {
        int a,b; cin>>a>>b;
        cout<<get(a,b).first<<' '<<get(a,b).second<<'\n';
    }
}