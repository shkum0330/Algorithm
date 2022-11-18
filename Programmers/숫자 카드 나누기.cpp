#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int div1=arrayA[0]; int div2=arrayB[0];
    vector<int> v;
    for(int i=1;i<=sqrt(arrayA[0]);i++){
        if(arrayA[0]%i==0){
            v.push_back(i);
            if(i != arrayA[0]/i) v.push_back(arrayA[0]/i);
        }
    }
    
    int res1=0; int res2=0;
    for(int i=0;i<v.size();i++){
        bool flag=true;
        for(int j=0;j<arrayA.size();j++){
            if(arrayA[j] % v[i] != 0) flag=false;
        }
        if(!flag) continue;
        for(int j=0;j<arrayB.size();j++){
            if(arrayB[j] % v[i] == 0) flag=false;
        }
        if(!flag) continue;
        res1=max(res1,v[i]);
    }
    v.clear();
     for(int i=1;i<=sqrt(arrayB[0]);i++){
        if(arrayB[0]%i==0){
            v.push_back(i);
            if(i != arrayB[0]/i) v.push_back(arrayB[0]/i);
        }
    }
    
    for(int i=0;i<v.size();i++){
        bool flag=true;
        for(int j=0;j<arrayB.size();j++){
            if(arrayB[j] % v[i] != 0) flag=false;
        }
        if(!flag) continue;
        for(int j=0;j<arrayA.size();j++){
            if(arrayA[j] % v[i] == 0) flag=false;
        }
        if(!flag) continue;
        res2=max(res2,v[i]);
    }
    answer=max(res1,res2);
    return answer;
}
