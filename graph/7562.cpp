#include <bits/stdc++.h>
using namespace std;

int length;
int startX,startY,destX,destY;
int board[301][301];
pair<int,int> moving[8]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
queue<pair<int,int>> q;
bool visited[301][301];
int dist[301][301];
int cnt;

void bfs(int y,int x){

    visited[y][x]= true;
    q.push({y,x});

    while (!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        if(board[y][x]==1) return;
        q.pop();

        for(int i=0;i<8;i++){
            int nx=x+moving[i].second;
            int ny=y+moving[i].first;
            if(nx>=length || nx<0 || ny>=length || ny<0) continue;

            if(!visited[ny][nx]){
                dist[ny][nx]=dist[y][x]+1;
                visited[ny][nx]= true;
                q.push({ny,nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        while (!q.empty()) q.pop();
        for (int i=0; i<301; i++){
            for (int j=0; j<301; j++){
               dist[i][j]=0;
               visited[i][j]= false;
               board[i][j]=0;
            }
        }
        cin>>length;
        cin>>startX>>startY;
        cin>>destX>>destY;
        board[destY][destX]=1;
        bfs(startY,startX);

        cout<<dist[destY][destX]<<'\n';
    }
}