#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    int turn=1; // 차례
    int person=2; // 사람 번호
    bool flag=true;
    s.insert(words[0]); // 첫번째 턴은 무조건 추가
    for(int i=1;i<words.size();i++){
        if(person==n+1){ // 한바퀴 돌았을 경우
            person=1;
            turn++; // 차례 1 증가
        }
        if(s.find(words[i]) != s.end() || words[i][0] != words[i-1][words[i-1].length()-1]){ // 이미 있는 단어를 말했거나, 끝말을 잇지 못한 경우
            flag=false;
            answer.push_back(person);
            answer.push_back(turn);
            break;
        }
        s.insert(words[i]);
        person++;
    }
    if(flag){ // 탈락자가 없을 경우
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
