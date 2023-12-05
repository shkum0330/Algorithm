#include <bits/stdc++.h>
using namespace std;

#define INF 1987654321
int n,m,treeN;
pair<int,int> arr[500001];

void update(int idx,int val){
    idx += (treeN-1);
    arr[idx].first=val;
    idx /= 2;
    while (idx>0){
        arr[idx]=min(arr[idx*2],arr[idx*2+1]);
        idx /= 2;
    }
}
int get(int start,int end){
    start += treeN-1;
    end += treeN-1;
    int res=0;
    pair<int,int> minValue={INF,INF};
    while (start<=end){
        if(start%2==1){
            minValue=min(minValue,arr[start]);

        }
        if(end%2==0){
            minValue=min(minValue,arr[end]);
        }
        start=(start+1)/2;
        end=(end-1)/2;
    }
    return minValue.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (treeN = 1; treeN < n; treeN = treeN << 1);
    for (int i = 0; i < n; ++i) {
        cin>>arr[treeN+i].first;
        arr[treeN+i].second=i+1;
    }
    for (int i = treeN+n; i < treeN*2; ++i) {
        arr[i].first=INF;
    }
    for(int i= treeN - 1; i > 0; i--){
        arr[i]= min(arr[i*2],arr[i*2+1]);
    }
    cin>>m;
    for (int i = 0; i < m; ++i) {
        int a,b,c; cin>>a>>b>>c;
        if(a==1){
            update(b,c);
        }else{
            cout<<get(b,c)<<'\n';
        }
    }
}