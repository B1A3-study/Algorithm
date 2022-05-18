#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool comp(string x, string y){
    if (x.size() != y.size())       return x.size() < y.size();

    return x < y;
}

int main(){
    vector<string> nums;
    vector<string> strs;
    string buff;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> buff;
        strs.push_back(buff);
    }

    for (int i = 0; i < N; i++){
        string tmp = "";
        for (int j = 0; j < strs[i].size(); j++){

            if (j == strs[i].size() - 1){ //마지막 인덱스일 때
                if (strs[i][j] >= '0' && strs[i][j] <= '9')  tmp += strs[i][j];
                if (tmp != "")  nums.push_back(tmp);
            }

            else if (strs[i][j] >= '0' && strs[i][j] <= '9'){ //0 제외 숫자일 때
                tmp += strs[i][j];
            }

            else { //문자일 때
                if (tmp != "")  {
                    nums.push_back(tmp); //비어있지 않으면 push
                    tmp = ""; //tmp 초기화
                }
            }
        }
    }

    for (int i = 0; i < nums.size(); i++){
        int cnt = 0;
        for (int j = 0; j < nums[i].size(); j++){
            if (nums[i][j] != '0'){ //앞에 0 붙은 애들 처리
                nums[i] = nums[i].substr(j);
                break;
            }

            else if (nums[i][j] == '0')     cnt++; //0으로만 이루어진 애들 처리

            if (cnt == nums[i].size())         nums[i] = "0";
        }
    }

    sort(nums.begin(), nums.end(), comp);

    for (auto el: nums){
        cout << el << '\n';
    }

    return 0;
}