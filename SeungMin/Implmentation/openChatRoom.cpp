#include <sstream>
#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

map<string, string> m;
vector<string> word, ids;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (int i = 0; i < record.size(); i++) {
        //string쪼개기, istringstream이 공백에 따라서 단어 짤라줌
        istringstream s(record[i]);
        string act, uid, name;
        s >> act >> uid >> name;

        //나갔는지 들어갔는지 확인하기
        if (act == "Enter") word.push_back("님이 들어왔습니다.");
        else if (act == "Leave") word.push_back("님이 나갔습니다.");

        //들어갔다 나갔다 하는 uid 로그 저장하기
        if (act == "Enter" || act == "Leave") ids.push_back(uid);
        //나가는게 아니면 닉변했는지 항상 체크
        if (act != "Leave") m[uid] = name;
    }
    for (int i = 0; i < ids.size(); i++) {
        answer.push_back(m[ids[i]] + word[i]);
    }
    return answer;
}