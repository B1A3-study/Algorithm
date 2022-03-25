#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int N, num, sum = 0, maxVal = -4001, roundedNum;
    vector<int> v, leastV;
    map<int, int> m;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> num;
        cin.ignore();
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int val: v){
        sum += val;
        m[val]++;
    }

    for (const auto& [key, value]: m){
        if (maxVal < value){
            maxVal = value;
        }
    }

    for (const auto& [key, value]: m){ //C++17 키-값 쌍 반복문
        if (maxVal == value){
            leastV.push_back(key);
        }
    }

    if (leastV.size() > 1){
        sort(leastV.begin(), leastV.end());
        num = leastV[1];
    } else {
        num = leastV[0];
    }

    if (round((double) sum / N) < 0 && round((double) sum / N) > -1){
        roundedNum = -1 * round((double) sum / N);
    } else {
        roundedNum = round((double) sum / N);
    }

    cout << roundedNum << '\n'; 
    cout << v[v.size() / 2] << '\n';
    cout << num << '\n';
    cout << v[v.size() - 1] - v[0] << '\n';

    return 0;
}