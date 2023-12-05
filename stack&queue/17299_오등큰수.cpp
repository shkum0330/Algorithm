#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef long long ll;
typedef pair<int,int> pii;

int n,maxf;
vector<int> v;
int f[1000001];
int res[1000001];
stack<pii> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int num; cin>>num;
        f[num]++;
        maxf=max(f[num],maxf);
        v.push_back(num);
    }


    for (int i = 0; i < n; ++i) {

        if(st.empty() || (!st.empty() && st.top().first>=f[v[i]])){
            st.push({f[v[i]],i});
            continue;
        }

        while (!st.empty() && st.top().first<f[v[i]]){
            res[st.top().second]=v[i];
            st.pop();
        }
        st.push({f[v[i]],i});
    }

    for (int i = 0; i < n; ++i) {
        if(res[i]==0) cout<<-1<<' ';
        else cout<<res[i]<<' ';
    }
    cout<<'\n';
}
