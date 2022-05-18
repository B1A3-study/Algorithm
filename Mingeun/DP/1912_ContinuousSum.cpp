#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long max(long long x, long long y){
    if (x > y)  return x;
    else        return y;
}

int N;

int main(){
    vector<int> nums;
    vector<long long> dp;
    long long maxV;
    cin >> N;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    dp.push_back(nums[0]);              //d1 = a1
    maxV = nums[0];
    /* dn = max(dn-1 + an, an)라고 생각해봄 */
    for (int i = 1; i < N; i++){
        dp.push_back(max(dp[i - 1] + nums[i], nums[i]));
    }

    for (const auto& el: dp){
        if (maxV < el)  maxV = el;
    }

    cout << maxV << '\n';

    return 0;
}