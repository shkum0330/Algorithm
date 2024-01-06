#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int g1,g2,g3; // 도넛,막대,8자 그래프의 개수
int vertex_size; // 정점의 개수
vector<int> e[1000001];
bool visited[1000001];
int inDegree[1000001];
int outDegree[1000001];
bool already;

void dfs(int v){
    for(auto& k:e[v]){
        if(!visited[k]){
            visited[k]=true;
            dfs(k);
        }
    }
}

bool bfs(int v){
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        if(e[tmp].size()==0) { // 갈곳이 없으면 막대 그래프
            visited[tmp]=true;
            return false;
        }
        for(auto& k:e[tmp]){
            if(!visited[k]){
                visited[k]=true;
                q.push(k);
                if(k==v) return true; // 자신으로 돌아오면 도넛 그래프
            }
            else {
                already=true;
                return false;
            }
        }
    }
    return false;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    for(int i=0;i<edges.size();i++){
        vertex_size=max({vertex_size,edges[i][0],edges[i][1]});
        e[edges[i][0]].push_back(edges[i][1]);
        inDegree[edges[i][1]]++;
        outDegree[edges[i][0]]++;
    }
    int start=0;
    for(int i=1;i<=vertex_size;i++){
        if(e[i].size()>1){ // 생성된 정점인지, 8자 그래프의 시작점인지 조사해야됨
            if(inDegree[i]==0){ // 들어오는 정점이 없으면 생성된 정점
                answer.push_back(i);
                start=i;
                visited[i]=true;
            } else { // 8자 그래프 모두 방문
                dfs(i);
                g3++;
            }
        }
    }
    for(int i=1;i<=vertex_size;i++){ // 도넛 그래프 찾기
        if(!visited[i]){
            already=false;
            if(bfs(i)) { // 도넛 그래프
                g1++;
            }
            else{
                if(already) continue;
                else g2++;
            }
        }
    }
    answer.push_back(g1);
    answer.push_back(g2);
    answer.push_back(g3);
    return answer;
}
