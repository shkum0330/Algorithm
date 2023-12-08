#include <bits/stdc++.h>
using namespace std;

int n,m;
int field[51][51];
bool visited[51][51];
int cnt;
pair<int,int> moving[8]={{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
queue<pair<int,int>> q;
int w,h;

void bfs(int y,int x){

    q.push({y,x});
    visited[y][x]=true;

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int ny=y+moving[i].first;
            int nx=x+moving[i].second;

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(!visited[ny][nx] && field[ny][nx] == 1){
                q.push({ny,nx});
                visited[ny][nx]=true;
            }

        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true){
        cnt=0;
        for (int i = 0; i < 51; ++i) {
            for (int j = 0; j < 51; ++j) {
                visited[i][j] = false;
            }
        }
        cin>>w>>h;
        if(w==0 && h==0) break;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin>>field[i][j];
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(field[i][j] && !visited[i][j]) {
                    bfs(i,j); cnt++;
                }
            }
        }


        cout<<cnt<<'\n';
    }

}
