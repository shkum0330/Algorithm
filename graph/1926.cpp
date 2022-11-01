#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[501][501];
bool visited[501][501];

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int area,maxArea=-1;
int cnt;
void dfs(int y,int x){
    visited[y][x]=true;
    area++;
    for (int i = 0; i < 4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if(!visited[ny][nx] && board[ny][nx]) dfs(ny,nx);
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);cin>>n>>m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!visited[i][j] && board[i][j]){
                cnt++;
                dfs(i,j);
            }

            maxArea=max(maxArea, area);
            area=0;
        }
    }
    cout<<cnt<<'\n';
    cout<<maxArea<<'\n';
}
