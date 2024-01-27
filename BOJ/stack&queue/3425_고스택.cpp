#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000000

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        vector<string> op;
        vector<ll> v;

        while (true) {
            string o;
            cin >> o;
            if (o=="QUIT") return 0;
            if (o == "END") break;
            if (o == "NUM") {
                ll num; cin >> num;
                v.push_back(num);
            }
            op.push_back(o);
        }

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            stack<ll> st;
            int idx=0;
            bool error_flag=false;
            ll num;
            cin >> num;
            st.push(num);
            for (auto &o: op) {
                if (o == "NUM") {
                    st.push(v[idx++]);
                }
                if (o == "POP") {
                    if (st.empty()) {
                        error_flag=true;
                        break;
                    }
                    st.pop();
                }
                if (o == "INV") {
                    if (st.empty()) {
                        error_flag=true;
                        break;
                    }
                    ll num = st.top();
                    st.pop();
                    st.push(-num);
                }
                if (o == "DUP") {
                    if (st.empty()) {
                        error_flag=true;
                        break;
                    }
                    st.push(st.top());
                }
                if (o == "SWP") {
                    if (st.size()<2) {
                        error_flag=true;
                        break;
                    }
                    ll n1 = st.top();
                    st.pop();
                    ll n2 = st.top();
                    st.pop();
                    st.push(n1);
                    st.push(n2);
                }
                if (o == "ADD") {
                    if (st.size()<2) {
                        error_flag=true;
                        break;
                    }
                    ll n1 = st.top();
                    st.pop();
                    ll n2 = st.top();
                    st.pop();
                    if (abs(n1+n2)>MAX) {
                        error_flag=true;
                        break;
                    }
                    st.push(n1 + n2);
                }
                if (o == "SUB") {
                    if (st.size()<2) {
                        error_flag=true;
                        break;
                    }
                    ll n1 = st.top();
                    st.pop();
                    ll n2 = st.top();
                    st.pop();
                    if (abs(n2-n1)>MAX) {
                        error_flag=true;
                        break;
                    }
                    st.push(n2 - n1);
                }
                if (o == "MUL") {
                    if (st.size()<2) {
                        error_flag=true;
                        break;
                    }
                    ll n1 = st.top();
                    st.pop();
                    ll n2 = st.top();
                    st.pop();
                    if (abs(n1*n2)>MAX) {
                        error_flag=true;
                        break;
                    }
                    st.push(n1 * n2);
                }
                if (o == "DIV") {
                    if (st.size()<2) {
                        error_flag=true;
                        break;
                    }
                    bool is_positive = true;
                    ll n1 = st.top();
                    st.pop();
                    ll n2 = st.top();
                    st.pop();
                    if (n1 == 0) {
                        error_flag=true;
                        break;
                    }
                    st.push(n2/n1);
                }
                if (o == "MOD") {
                    if (st.size()<2) {
                        error_flag=true;
                        break;
                    }
                    bool is_positive=true;
                    ll n1 = st.top();
                    st.pop();
                    ll n2 = st.top();
                    st.pop();
                    if (n1 == 0) {
                        error_flag=true;
                        break;
                    }
                    st.push(n2%n1);
                }
            }
            if(st.size() != 1 || error_flag) cout<<"ERROR"<<'\n';
            else cout<<st.top()<<'\n';
        }
        cout<<'\n';
    }
}
