#include <bits/stdc++.h>
using namespace std;

struct prob{
    int score,num;
};
bool compare(const prob& a, const prob& b){
    return a.score<b.score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    prob arr[8];
    for(int i=0;i<8;i++) {
        cin>>arr[i].score; arr[i].num=i+1;
    }
    sort(arr,arr+8,compare);

    int sum=0;
    vector<int> v;
    for(int i=7;i>2;i--){
        sum += arr[i].score;
        v.push_back(arr[i].num);
    }
    sort(v.begin(),v.end());
    cout<<sum<<'\n';
    for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
    cout<<'\n';
}