#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Music{
    int time;
    string title;
    int sheet;
};

vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos=0;
    string token="";
    while ((pos=input.find(delimiter)) != string::npos){
        token=input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    int playtime=-1;
    
    vector<string> m_code;
    for(int i=0;i<m.size();i++){
        string tmp="";
         if(m[i+1]=='#'){
            tmp += m[i];
            tmp += m[i+1];
            m_code.push_back(tmp);
            i++;
        }else{
            tmp += m[i];
            m_code.push_back(tmp);
        }
    }
    
    for(int k=0;k<musicinfos.size();k++){
        vector<string> tokens=split(musicinfos[k],",");
        vector<string> s=split(tokens[0],":");
        vector<string> e=split(tokens[1],":");
        int time=stoi(e[0])*60+stoi(e[1])-stoi(s[0])*60-stoi(s[1]);
        vector<string> code;
        for(int i=0;i<tokens[3].size();i++){
            string tmp="";
            
            if(tokens[3][i+1]=='#'){
                tmp += tokens[3][i];
                tmp += tokens[3][i+1];
                code.push_back(tmp);
                i++;
            }else{
                tmp += tokens[3][i];
                code.push_back(tmp);
            }
        }
        int len=code.size();
        
        int quot=time/len;
        int rem=time%len;
        
        vector<string> full_music;
        for(int i=0;i<quot;i++){
            for(int j=0;j<code.size();j++){
                full_music.push_back(code[j]);
            }
        }
        for(int i=0;i<rem;i++){
            full_music.push_back(code[i]);
        }

 
        if(m_code.size()>full_music.size()) continue;
        for(int i=0;i<=full_music.size()-m_code.size();i++){
            string tmp="";
            for(int j=0;j<m_code.size();j++){
                tmp += full_music[i+j];
            }
            if(tmp == m && playtime<time){
                answer=tokens[2];
                playtime=time;
            }
        }
    }
    if(playtime==-1) answer="(None)";
    return answer;
}
