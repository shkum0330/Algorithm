#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};

int mmap[101][101];
bool visited[101][101];
int dist[101][101];
bool border[101][101];

queue<pair<int,int>> q;

void check(int y,int x){
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(mmap[ny][nx]==0){
            border[y][x]=true;
            return;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2;
    int max_x=0; int max_y=0;
    for(int i=0;i<rectangle.size();i++){
        int y1=rectangle[i][1]*2;
        int y2=rectangle[i][3]*2;
        int x1=rectangle[i][0]*2;
        int x2=rectangle[i][2]*2;
        max_x=max(max_x,x2);
        max_y=max(max_y,y2);
            
        for(int y=y1; y<=y2; y++){ // 세로선
            for(int x=x1; x<=x2; x++){ // 가로선
                mmap[y][x]=1;
            }
        }
    }

     for(int i=0;i<rectangle.size();i++){
        int y1=rectangle[i][1]*2;
        int y2=rectangle[i][3]*2;
        int x1=rectangle[i][0]*2;
        int x2=rectangle[i][2]*2;
        max_x=max(max_x,x2);
        max_y=max(max_y,y2);
         
        for(int y=y1+1; y<y2; y++){
            for(int x=x1+1; x<x2; x++){
                mmap[y][x]=0;
            }
        }
     }
    
    q.push({characterY,characterX});
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        if(y==itemY && x==itemX) break;
        visited[y][x]=true;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0 || ny>max_y || nx<0 || nx>max_x) continue;
            
            if(!visited[ny][nx] && mmap[ny][nx]==1){
                q.push({ny,nx});
                dist[ny][nx]=dist[y][x]+1;
            }
            
        }
    }
    
    answer=dist[itemY][itemX]/2;
    return answer;
}
