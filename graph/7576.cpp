#include <bits/stdc++.h>
using namespace std;

int n,m;
int tomato[1001][1001];

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

queue<pair<int,int>> q;
bool visited[1001][1001];


void bfs(){

    while (!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=m || nx<0 || ny>=n || ny<0) continue;

            if(!visited[ny][nx] && tomato[ny][nx]==0){
                tomato[ny][nx]=tomato[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>m>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>tomato[i][j];
            if(tomato[i][j]==1){
                q.push({i,j});
            }
        }

    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tomato[i][j]==0) {
                cout<<-1<<'\n';
                return 0;
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(res<tomato[i][j]) {
                res=tomato[i][j];
            }
        }
    }
    cout<<res-1<<'\n';
}