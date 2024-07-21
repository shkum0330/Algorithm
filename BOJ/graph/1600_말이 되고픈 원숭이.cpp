#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int,int> pii;

struct Point{
    int y,x,r;
};
int k,w,h;
int res=INF;
int mmap[201][201];
int dist[31][201][201];
bool visited[31][201][201];
queue<Point> q;
int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};
pii mv[8]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>k>>w>>h;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin>>mmap[i][j];
        }
    }

    q.push({0,0,k});
    visited[k][0][0]=true;

    while (!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int r=q.front().r;
        q.pop();
        if(y==h-1 && x==w-1){
            continue;
        }

        if(r>0) {
            for (int i = 0; i < 8; ++i) {
                int ny = y + mv[i].first;
                int nx = x + mv[i].second;
                if (ny >= h || ny < 0 || nx >= w || nx < 0) continue;

                if (mmap[ny][nx] == 0 && !visited[r - 1][ny][nx]) {
                    dist[r - 1][ny][nx] = dist[r][y][x] + 1;
                    visited[r - 1][ny][nx] = true;
                    q.push({ny, nx, r - 1});
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=h || ny<0 || nx>=w || nx<0) continue;

            if(mmap[ny][nx]==0 && !visited[r][ny][nx]){
                dist[r][ny][nx]= dist[r][y][x] + 1;
                visited[r][ny][nx]=true;
                q.push({ny,nx,r});
            }
        }
    }

    for (int i = 0; i <= k; ++i) {
        if(!visited[i][h-1][w-1]) continue;
        res=min(res, dist[i][h-1][w-1]);
    }

    if(res==INF) cout<<-1<<'\n';
    else cout<<res<<'\n';
}
