#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    for(int i=0;i<moves.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[j][moves[i]-1]){
        
                if(st.empty() || st.top()!=board[j][moves[i]-1]){
                    st.push(board[j][moves[i]-1]);
                 
                    board[j][moves[i]-1]=0;
                    break;
                }
                if(st.top()==board[j][moves[i]-1]){
                    cout<<st.top()<<' ';
                    answer += 2;
                    st.pop();
                    board[j][moves[i]-1]=0;
                    break;
                }
            }
        }
    }

    return answer;
}
