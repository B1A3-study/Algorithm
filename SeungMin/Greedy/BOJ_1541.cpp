#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
//BOJ 1541 읽어버린 괄호 문제(Greedy)
using namespace std;

int main(){
    string input;
    int answer=0;
    int ntemp=0;
    string temp = "";
    bool minus = false;
    cin >> input;
    for(int i=0 ; i<=input.size() ; i++){
        if(input[i] == '-' || input[i] == '+' || i==input.size()){
            if(minus) answer -= stoi(temp);
            else answer += stoi(temp);
            temp = "";
            //-가 한번이라도 나오면 그 순간부터는 다빼야함
            if(input[i]=='-') minus = true;
            continue;
        }
        temp += input[i];
    }

    cout << answer;
    return 0;
}