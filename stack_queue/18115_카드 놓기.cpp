#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        v.push_back(a);
    }
    deque<int> d;
    int cardNum=1;

    for(int i=n-1;i>=0;i--){
        if(v[i]==1){
            d.push_front(cardNum);
        }else if(v[i]==2){
            if(d.empty()) d.push_back(cardNum);
            else{
                int tmp=d.front();
                d.pop_front();
                d.push_front(cardNum);
                d.push_front(tmp);
            }
        }
        else if(v[i]==3){
            d.push_back(cardNum);
        }
        cardNum++;
    }

    while(!d.empty()){
        cout<<d.front()<<' ';
        d.pop_front();
    }
    cout<<'\n';
}

// 2 3 3 2 1

// 1 5 2 3 4