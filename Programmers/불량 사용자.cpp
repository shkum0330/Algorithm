#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int e[9][9];
int userSize,banSize;
set<int> s;
set<set<int>> res;

void dfs(int idx){
    if(idx==banSize){
        if(res.find(s)==res.end()) {
            res.insert(s);
        }
        return;
    }
    for(int i=0;i<userSize;i++){
        if(e[idx][i] && s.find(i)==s.end()){
            s.insert(i);
            dfs(idx+1);
            s.erase(i);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    banSize=banned_id.size();
    userSize=user_id.size();
    for(int i=0;i<banned_id.size();i++){
        for(int j=0;j<user_id.size();j++){
            if(banned_id[i].size() != user_id[j].size()) continue;
            bool flag=true;
            for(int k=0;k<user_id.size();k++){
                if(banned_id[i][k] != user_id[j][k] && banned_id[i][k] != '*') {
                    flag=false;
                    break;
                }
            }
            if(flag) e[i][j]=1;
        }
    }

    dfs(0);
    answer=res.size();
    return answer;
}
