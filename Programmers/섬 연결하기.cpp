#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

struct Edge{
    int s,e,c;
};

bool compare(const Edge& a, const Edge& b){
    return a.c<b.c;
}

vector<Edge> e;

int find(int a){
    if(a==parent[a]) return a;
    else return parent[a]=find(parent[a]);
}

bool merge(int a, int b){
    int a_root=find(a);
    int b_root=find(b);
    if(a_root==b_root) return false;
    parent[b_root]=a_root;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<n;i++) parent[i]=i;
    
    for(int i=0;i<costs.size();i++){
        e.push_back({costs[i][0],costs[i][1],costs[i][2]});
    }
    sort(e.begin(),e.end(),compare);
    
    for(int i=0;i<e.size();i++){
        if(merge(e[i].s,e[i].e)){
            answer += e[i].c;
        }
    }
    
    return answer;
}
