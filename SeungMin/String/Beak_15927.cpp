#include <bits/stdc++.h>

using namespace std;

int palindrome(const string& str) {
    string word = str;
    //회문인지 체크
    for (int i = 0; i < (int)word.size() / 2; i++) {
        if (word[i] != word[word.size() - i - 1]) {
            return word.size();
        }
    }
    //모두 같지 않으면 중간에 하나만 깨져도 회문이 깨짐
    for (int i = 0; i < (int)word.size(); i++) {
        if (word[0] != word[word.size() - i - 1]) return word.size() - 1;
    }
    //모두 같다면 -1
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    cout << palindrome(str);

    return 0;
}