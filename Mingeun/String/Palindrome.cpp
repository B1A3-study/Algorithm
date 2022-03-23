#include <iostream>

using namespace std;

string str;

bool isPalindrome(int start, int end){
    for (int i = start; i <= end / 2; i++){
        if (str[i] != str[end - i]){
            return false;
        }
    }

    return true;
}

int main(){
    int answer = -1, sameCH = 1;    

    cin >> str;

    for (int i = 0; i < str.size() - 1; i++){ //다 같은 글자거나 한 글자짜리일 때 flag
        if (str[i] != str[i + 1]){
            sameCH = -1;
            break;
        }
    }
    

    if (sameCH == 1 || str.size() == 1){
        answer = -1;
    }

    else if (!isPalindrome(0, str.size() - 1)){ // 팰린드롬이 아닐 때
        answer = str.size();
    }

    else {
        answer = str.size() - 1; //팰린드롬일 때
    }

    cout << answer << '\n';

    return 0;
}