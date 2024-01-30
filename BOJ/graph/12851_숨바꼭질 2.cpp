#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n,k,cnt;
int res=INF;
int dist[100001];
queue<int> q;

void bfs(int v) {
    q.push(v);
    while (!q.empty()){
        int curr=q.front();
        q.pop();
        if(curr==k && res>=dist[curr]){
            res=dist[curr];
            cnt++;
        }

        for (int i = 0; i < 3; ++i) {
            int next;
            if(i==0) next=curr-1;
            if(i==1) next=curr+1;
            if(i==2) next=curr*2;

            if(next>100000 || next<0) continue;

            if(dist[next]==0 || dist[next]==dist[curr]+1){
                q.push(next);
                dist[next]=dist[curr]+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>k;

    bfs(n);

    cout<<res<<'\n';
    cout<<cnt<<'\n';
}
