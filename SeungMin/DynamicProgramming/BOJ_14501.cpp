#include <iostream>
#include <algorithm>

using namespace std;

int N,tmp;
int T[1001];
int P[1001];
int dp[1001];

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> T[i] >> P[i];
    }
    for(int i=n ; i>=1 ; i--){
        //일은 n+1까지 할 수 있음
        if(i+T[i] > n+1) dp[i] = dp[i+1];
        else dp[i] = max(dp[i+1], dp[i+T[i]]+P[i]);
    }
    cout << dp[1] << '\n';
}