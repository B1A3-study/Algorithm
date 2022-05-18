#include <iostream>

using namespace std;

int n;
int dp[100001];
int num[100001];

// 0과 음수값 중에서 최댓값 찾는 함수
int max_minus(){
    int max = num[0];
    for(int i = 1; i < n; i++){
        if(max < num[i]){
            max = num[i];
        }
    }
    return max;
}

// 최댓값을 찾는 함수
int max_value(int idx){
    int result = dp[0];
    for(int i = 1; i <= idx; i++){
        dp[i] = max(dp[i-1] + dp[i], dp[i]);
    }
    for(int i = 1; i <= idx; i++){
        result = max(result, dp[i]);
    }
    return result;
}

int main(void){
    int idx = 0, plus = 0, minus = 0;
    int check = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        if(num[i] <= 0) check++;
    }
    // 입력값이 음수와 0으로만 이루어졌을 경우
    if(check == n){
        cout << max_minus();
        return 0;
    }
    // plus와 minus를 뭉쳐주기
    for(int i = 0; i < n; i++){
        if(num[i] < 0){
            if(plus != 0){
                dp[idx++] = plus;
                plus = 0;
            }
            minus += num[i];
        }
        else{
            if(minus != 0){
                dp[idx++] = minus;
                minus = 0;
            }
            plus += num[i];
        }
    }
    if(plus != 0){
        dp[idx] = plus;
    }
    if(minus != 0){
        dp[idx] = minus;
    }
    cout << max_value(idx);
}