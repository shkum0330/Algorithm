#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string,int> m;
    int len=100001;
    set<string> l;
    for(int i=0;i<gems.size();i++){
        l.insert(gems[i]);
    }
    int size=l.size();
    int s=0; int e=0;
    set<string> st;
    while(s<gems.size() && e<gems.size() && s<=e){
        
        st.insert(gems[e]);
        m[gems[e]]++;
     
        while(st.size()==size){
            if(e-s<len){ // 정답 갱신
                answer[0]=s+1; answer[1]=e+1;
                len=e-s;
            }
            if(m[gems[s]]==1){
                cout<<s<<' '<<e<<' '<<st.size()<<'\n';
                m[gems[s]]=0;
                st.erase(gems[s]);
            
            }else m[gems[s]]--;
            s++;
        }
        e++;
      
    }
    
    return answer;
}
