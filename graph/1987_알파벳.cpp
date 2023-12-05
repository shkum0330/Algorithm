#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

bool visited[26];
char board[21][21];
int mx[4]={0,1,0,-1};
int my[4]={1,0,-1,0};
int r,c,res;

void dfs(int y,int x,int cnt){
    res=max(cnt,res);

    for (int i = 0; i < 4; ++i) {
        int ny=y+my[i];
        int nx=x+mx[i];
        if(ny>=r || ny<0 || nx>=c || nx<0) continue;
        if(!visited[board[ny][nx]-'A']){
            visited[board[ny][nx]-'A']=true;
            dfs(ny,nx,cnt+1);
            visited[board[ny][nx]-'A']=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>r>>c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>board[i][j];
        }
    }
    visited[board[0][0]-'A']=true;
    dfs(0,0,1);
    cout<<res<<'\n';
}