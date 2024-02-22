#include <string>
#include <vector>
#include <queue>

using namespace std;

int n,m;
char mmap[101][101];
bool visited[101][101];
pair<int,int> s,e;
int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};

int bfs(pair<int,int> start){
    queue<pair<pair<int,int>,int>> q;
    q.push({start,0});
    
    while(!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        
        if(mmap[y][x]=='G'){
            return cnt;
        }
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=n || ny<0 || nx>=m || nx<0) continue; // 이동 자체가 불가능할때

            while(true){
                if(mmap[ny][nx]=='D' || ny>=n || ny<0 || nx>=m || nx<0){ // 뒤로가기
                    ny += dy[(i+2)%4];
                    nx += dx[(i+2)%4];
                    break;
                }
                ny += dy[i];
                nx += dx[i];
            }

            if(!visited[ny][nx]){
                q.push({{ny,nx},cnt+1});
                visited[ny][nx]=true;
            }

        }
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    n=board.size();
    m=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mmap[i][j]=board[i][j];
            if(mmap[i][j]=='R') s={i,j};
        }
    }
    
    answer= bfs(s);
    
    return answer;
}
