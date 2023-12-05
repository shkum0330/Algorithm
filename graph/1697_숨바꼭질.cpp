#include <bits/stdc++.h>
using namespace std;

int n,k;
bool visited[100001];
queue<pair<int,int>> q;

void bfs(int vertex){
    while(!q.empty()){
        int location=q.front().first;
        int t=q.front().second;
        q.pop();

        if(location==k){
            cout<<t<<'\n';
            return;
        }

        if(!visited[location-1] && location-1>=0 && location-1<=100000){
            visited[location-1]=true;
            q.push({location-1,t+1});

        }
        if(!visited[location+1] && location+1>=0 && location+1<=100000){
            visited[location+1]=true;
            q.push({location+1,t+1});
        }
        if(!visited[location*2] && location*2>=0 && location*2<=100000){
            visited[location*2]=true;
            q.push({location*2,t+1});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;

    visited[n]=true;
    q.push({n,0});
    bfs(n);
}
