#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int ccw(int x1,int y1,int x2,int y2,int x3,int y3) {
    int op=x1*y2+x2*y3+x3*y1 - (y1*x2+y2*x3+y3*x1);

    if(op>0) return 1;
    else if(op<0) return -1;
    else return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    pii arr[3];
    for (int i = 0; i < 3; ++i) {
        cin>>arr[i].first>>arr[i].second;
    }
    cout<<ccw(arr[0].first,arr[0].second,arr[1].first,arr[1].second,arr[2].first,arr[2].second)<<'\n';
}