#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct Point{
    int y,x,r;
};

int n,m,k;
int mmap[1001][1001];
int dist[11][1001][1001];
bool visited[11][1001][1001];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
queue<Point> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>m>>k;

    for (int i = 0; i < n; ++i) {
        string s;  cin>>s;
        for (int j = 0; j < m; ++j) {
            mmap[i][j]=s[j]-'0';
        }
    }

    q.push({0,0,k});
    visited[k][0][0]=true;
    while (!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int r=q.front().r;
        q.pop();

        if(y==n-1 && x==m-1) {
            cout << dist[r][n-1][m-1]+1 << '\n';
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;

            if(mmap[ny][nx]==0 && !visited[r][ny][nx]){
                dist[r][ny][nx]=dist[r][y][x]+1;
                visited[r][ny][nx]=true;
                q.push({ny,nx,r});
            }else if(mmap[ny][nx]==1){
                if(r==0) continue;
                if(!visited[r-1][ny][nx]){
                    dist[r-1][ny][nx]=dist[r][y][x]+1;
                    visited[r-1][ny][nx]=true;
                    q.push({ny,nx,r-1});
                }
            }
        }
    }

   cout<<-1<<'\n';
}
