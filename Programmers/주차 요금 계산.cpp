#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m;

//    [180, 5000, 10, 600]


    for (int i = 0; i < records.size(); ++i) {
        string time, carNum;
        time = records[i].substr(0, 5);
        carNum = records[i].substr(6, 4);
        m[carNum].push_back(time);
    }
        for (auto& iter: m) {
            if (iter.second.size() % 2 == 1) iter.second.push_back("23:59");
            int totalMinute=0;
            int fee = fees[1];
            for (int i = 0; i < iter.second.size() - 1; i += 2) {
                int hour = stoi(iter.second[i + 1].substr(0, 2)) - stoi(iter.second[i].substr(0, 2));
                int minute = stoi(iter.second[i + 1].substr(3, 2)) - stoi(iter.second[i].substr(3, 2));
                totalMinute += (hour * 60 + minute);
            }

            if(totalMinute>fees[0]){
                fee += ceil((totalMinute-fees[0])/(double)fees[2])*fees[3];
            }
            answer.push_back(fee);

        }

        return answer;
    }
