#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int idx=0;
    vector<pair<int,double>> v;
    vector<double> area;
    v.push_back({idx,k});
    idx++;
    while(k!=1){
        if(k%2 != 0) k= k*3+1;
        else k/=2;
        v.push_back({idx,k});
        idx++;
    }
    idx--;
    for(int i=0;i<v.size();i++){
        area.push_back((v[i].second+v[i+1].second)/2);
    }
    for(int i=0;i<ranges.size();i++){
        int a=ranges[i][0]; int b=idx+ranges[i][1];
        if(a==b) answer.push_back(0);
        else if(a>b) answer.push_back(-1);
        else{
            double tmp=0;
            for(int j=a;j<b;j++){
                tmp += area[j];
            }
            answer.push_back(tmp);
        }
        
    }
    return answer;
}
