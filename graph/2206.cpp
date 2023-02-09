#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000000

int n,m;
int board[1001][1001];
int dist[1001][1001][2];
int movex[4]={0,-1,0,1};
int movey[4]={-1,0,1,0};
queue<pair<pii,int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin>>s;
        for (int j = 0; j < m; ++j) {
            board[i][j]=s[j]-'0';
        }
    }
    q.push({{0,0},1});
    dist[0][0][1]=1;

    while (!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int wall=q.front().second;
        q.pop();
        if(y==n-1 && x==m-1) {
            cout << dist[n-1][m-1][wall] << '\n';
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx=x+movex[i];
            int ny=y+movey[i];
            if (nx>=m || nx<0 || ny>=n || ny<0) continue;

            if(board[ny][nx]==1 && wall){
                dist[ny][nx][wall-1] = dist[y][x][wall]+1;
                q.push({{ny,nx},wall-1});
            }
            if(board[ny][nx]==0 && dist[ny][nx][wall]==0){
                dist[ny][nx][wall] = dist[y][x][wall]+1;
                q.push({{ny,nx},wall});
            }
        }
    }
    if(dist[n-1][m-1][1]==0 && dist[n-1][m-1][0]==0) {
        cout<<-1<<'\n';
    }
}
