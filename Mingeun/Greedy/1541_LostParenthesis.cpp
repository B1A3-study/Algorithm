#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    vector<char> ops;
    string str, buff = "";
    int res = 0;

    getline(cin, str);
    
    for (int i = 0; i < str.size(); i++){
        if (str[i] == '+' || str[i] == '-'){ // 연산자 만났을 때
            nums.push_back(stoi(buff));
            ops.push_back(str[i]);
            buff = "";
            continue;
        }

        buff += str[i];

        if (i == str.size() - 1){ // 마지막 index일 때
            nums.push_back(stoi(buff));
        }
    }

    for (int i = 0; i < ops.size(); i++){
        if (ops[i] == '+'){
            nums[i + 1] += nums[i];
            ops.erase(ops.begin() + i);
            nums.erase(nums.begin() + i);
            i--; // 인덱스 줄여서 다 돌 수 있게 함
        }
    }

    res = nums[0];

    for (int i = 0; i < ops.size(); i++){
        if (ops[i] == '+')      res += nums[i + 1];
        else if (ops[i] == '-') res -= nums[i + 1];
    }

    cout << res << '\n';

    // for (auto el: nums){
    //     cout << el << ' ';
    // }
    // cout << endl;
    // for (auto el: ops){
    //     cout << el << ' ';
    // }

    return 0;
}