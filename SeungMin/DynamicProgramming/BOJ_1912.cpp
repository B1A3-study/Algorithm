#include <iostream>
#include <vector>

using namespace std;

int max_check(int a, int b){
    if(a>b) return a;
    else return b;
}

int main()
{
    int n,a;
    int answer;
    int dp[1000001];
    vector<int> nums;
    
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a;
        nums.push_back(a);
    }
    answer = nums[0];
    dp[0] = nums[0];

    for(int i=1 ; i<nums.size() ; i++){
        dp[i] = max_check(dp[i-1]+nums[i],nums[i]);
        answer = max_check(dp[i],answer);
    }
    cout << answer;
    return 0;
}