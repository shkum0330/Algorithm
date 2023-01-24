#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
double arr1[501];
double arr2[501];

bool compare(pair<double,int>& a,pair<double,int>& b){
    if(a.first!=b.first) return a>b;
    else return a<b;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<double,int>> fail;
    for(int i=1;i<=N;i++){
        for(int j=0;j<stages.size();j++){
            if(stages[j]>=i) arr1[i]++;
        }
    }
    for(int i=0;i<stages.size();i++){
        arr2[stages[i]]++;
    }
    for(int i=1;i<=N;i++){
        if(arr1[i]==0) fail.push_back({0,i});
        else fail.push_back({arr2[i]/arr1[i],i});
    }
    
    sort(fail.begin(),fail.end(),compare);
    for(int i=0;i<N;i++) answer.push_back(fail[i].second);
    return answer;
}
// 문제를 똑바로 읽자
