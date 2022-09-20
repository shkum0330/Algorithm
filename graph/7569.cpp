#include <bits/stdc++.h>
using namespace std;

int h,n,m;
int board[101][101][101];
struct tomato{
    int x,y,z;
};
int dx[6]={0,-1,0,1,0,0};
int dy[6]={-1,0,1,0,0,0};
int dz[6]={0,0,0,0,-1,1};
queue<tomato> q;


void bfs(){

    while (!q.empty()){
        int z=q.front().z;
        int y=q.front().y;
        int x=q.front().x;
        q.pop();

        for(int i=0;i<6;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nz=z+dz[i];
            if(nx>=m || nx<0 || ny>=n || ny<0 || nz>=h || nz<0) continue;

            if(board[nz][ny][nx] == 0){
                board[nz][ny][nx]= board[z][y][x] + 1;
                q.push({nx,ny,nz});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>m>>n>>h;

    for(int k=0;k<h;k++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> board[k][i][j];
                if (board[k][i][j] == 1) {
                    q.push({j, i,k});
                }
            }
    }
    bfs();
    for(int k=0;k<h;k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[k][i][j] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    int res=0;
    for(int k=0;k<h;k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (res < board[k][i][j]) {
                    res = board[k][i][j];
                }
            }
        }
    }
    cout<<res-1<<'\n';
}