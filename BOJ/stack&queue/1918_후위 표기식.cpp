#include <bits/stdc++.h>
using namespace std;

#define INF 0x7fffffff

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string exp; cin>>exp;
    stack<char> st;

    for (int i = 0; i < exp.size(); ++i) {
        if(exp[i]>='A' && exp[i]<='Z') cout<<exp[i];
        else {
            if(st.empty()){
                st.push(exp[i]);
                continue;
            }
            if (exp[i] == '(') {
                st.push(exp[i]);
            }
            if (exp[i] == ')') {
                while (!st.empty()) {
                    if (st.top() == '(') {
                        st.pop();
                        break;
                    }
                    cout << st.top();
                    st.pop();
                }
            }
            if (exp[i] == '*' || exp[i] == '/') {
                while (!st.empty()) {
                    if(st.top()=='(' || st.top()==')' || st.top()=='+' || st.top()=='-'){
                        break;
                    }
                    cout<<st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
            if (exp[i] == '+' || exp[i] == '-') {
                while (!st.empty()) {
                    if(st.top()=='(' || st.top()==')'){
                        break;
                    }
                    cout<<st.top();
                    st.pop();
                }

                st.push(exp[i]);
            }
        }
    }
    while (!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<'\n';
}
