#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> users;
    string row[3];
    
    for (string str: record){
        int index = 0;
        string strBuff;        
        istringstream ss(str);
        
        while (ss >> strBuff){ //한 줄에 다 넣기
            row[index++] = strBuff;
        }
        
        if (row[0] == "Enter"){
            users[row[1]] = row[2]; 
        } 
        
        else if (row[0] == "Change"){
            users[row[1]] = row[2];
        }
        
    }
    
    for (string str: record){
        int index = 0;
        string strBuff;        
        istringstream ss(str);
        
        while (ss >> strBuff){ //한 줄에 다 넣기
            row[index++] = strBuff;
        }
        
        if (row[0] == "Enter"){
            answer.push_back(users[row[1]] + "님이 들어왔습니다.");
        } 
        
        else if (row[0] == "Change"){
            continue;
        }
        
        else {
            answer.push_back(users[row[1]] + "님이 나갔습니다.");
        }
        
    }
    
    
    return answer;
}