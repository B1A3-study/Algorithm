#include <bits/stdc++.h>

using namespace std;

vector<string> serial_numbers;

bool all_compare(string str1, string str2) {
    int sum_i = 0, sum_j = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (isalpha(str1[i]) == 0) sum_i += (int)str1[i] - 48;
    }
    for (int j = 0; j < str2.size(); j++) {
        if (isalpha(str2[j]) == 0) sum_j += (int)str2[j] - 48;
    }
    if (str1.size() != str2.size()) {
        //길이가 다를때 짧은거부터
        return str1.size() < str2.size();
    }
    else {
        //길이가 같고 합이 다를때
        if (sum_i != sum_j) return sum_i < sum_j;
        //길이도 같고 합도 같을때
        else return str1 < str2;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string serial;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, serial);
        serial_numbers.push_back(serial);
    }
    sort(serial_numbers.begin(), serial_numbers.end(), all_compare);
    for (int i = 0; i < n; i++) cout << serial_numbers[i] << '\n';
    return 0;
}