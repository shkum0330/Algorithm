#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool compare(const pair<int,pair<string,int>> a,const pair<int,pair<string,int>> b){
    if(a.first==b.first){
        return a.second.second<b.second.second;
    }else return a.first>b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int,pair<string,int>>> v;
    vector<vector<int>> album; // 인덱스, 장르, 등장 횟수
    set<string> genre; // 장르 set으로 저장
    map<string,int> m;
    vector<pair<int,int>> sum;
    for(int i=0;i<plays.size();i++){
        v.push_back({plays[i],{genres[i],i}});
    }
    sort(v.begin(),v.end(),compare);

    int num=0;
    for(int i=0;i<plays.size();i++){
        if(genre.find(v[i].second.first) == genre.end()){ // 없는 장르면 새로운 배열 생성
            vector<int> nv;
            m[v[i].second.first]=num;
            sum.push_back({v[i].first,num});
            num++;
            genre.insert(v[i].second.first);
            nv.push_back(v[i].second.second);
            album.push_back(nv);
        }else{ // 있는 장르면 해당 장르 재생횟수 더하고 인덱스 push
            int idx=m[v[i].second.first];
            sum[idx].first += v[i].first;
            album[idx].push_back(v[i].second.second);
        }
    }
    sort(sum.rbegin(),sum.rend()); // 재생횟수 합으로 오름차순 정렬
  
    for(int i=0;i<album.size();i++){
        int index=sum[i].second;
        if(album[index].size()==1){ // 곡이 1개일때
            answer.push_back(album[index][0]);
        }
        else { // 2개일때
            for(int j=0;j<2;j++){
            answer.push_back(album[index][j]);
                }
            }
    }
    return answer;
}
