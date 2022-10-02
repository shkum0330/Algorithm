#include <string>
#include <vector>

using namespace std;
int e[101][101];
bool visited[101];
int cnt1,cnt2;
int cnt;

void dfs(int v,int n){
    visited[v]=true;
    cnt++;
    for (int i = 1; i <= n; ++i) {
        if(e[v][i] && !visited[i]) {
            dfs(i, n);

        }

    }
    visited[v]= false;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 1999999999;
    for (int i = 0; i < wires.size(); ++i) {
        e[wires[i][0]][wires[i][1]]=1;
        e[wires[i][1]][wires[i][0]]=1;
    }
    for (int i = 0; i < wires.size(); ++i) {
        int a=wires[i][0]; int b=wires[i][1];
        e[a][b]=0;
        e[b][a]=0;
        dfs(a,n);
        cnt1=cnt;
        cnt=0;
        dfs(b,n);
        cnt2=cnt;
        cnt=0;
        answer=min(answer,abs(cnt1-cnt2));
        e[a][b]=1;
        e[b][a]=1;
    }
    return answer;

}
