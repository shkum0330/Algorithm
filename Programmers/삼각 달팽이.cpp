#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];
int dy[3]={1,0,-1};
int dx[3]={0,1,-1};

vector<int> solution(int n) {
    vector<int> answer;

    int cnt=1;
    int y=0; int x=0; int d=0;
    
    while(cnt<=n*(n+1)/2){
        arr[y][x]=cnt++;
        if((y==n-1 && (x==0 || x==n-1)) || arr[y+dy[d]][x+dx[d]]) {
            d=(d+1)%3;
        }
        y += dy[d];
        x += dx[d];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(arr[i][j]);
        }
    }

    return answer;
}
