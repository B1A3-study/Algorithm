#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int testCase;
vector<string> list;
vector<string> answer;

//전화번호 목록(gold 4)
int main()
{
    int n;
    string num;
    cin >> testCase;

    for(int i=0 ; i<testCase ;i++){
        bool check = true;
        cin >> n;
        cin.ignore();

        for(int j=0 ; j<n ;j++){
            getline(cin, num);
            list.push_back(num);
        }
        //사전순 정렬이 키워드
        sort(list.begin(), list.end());

        for(int t=0 ; t<n-1 ; t++){
            int length = list[t].size();
            if(list[t].size() >= list[t+1].size()) continue;

            if(list[t] == list[t+1].substr(0,length)){
                check = false;
                cout << "NO" << '\n';
                break;
            }
        }
        if(check == true) cout << "YES" << '\n';
        list.clear();
    }
    return 0;
}