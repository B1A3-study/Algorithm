#include <iostream>

using namespace std;

int result_cnt;
bool check=false;

void dfs(long long int a, long long int b, int cnt)
{
    if(a == b) {
        check=true;
        result_cnt = cnt;
        return;
    }
    else if(a > b) return;

    cnt++;
    dfs(a*2,b,cnt);
    dfs(a*10+1,b,cnt);                                                  
}

int main()
{
    int cnt=0;
    //첫째 줄에 A, B (1 ≤ A < B ≤ 10^9)가 주어진다.
    //조건 잘 읽어보자
    long long int num1,num2;
    cin >> num1 >> num2;
    dfs(num1,num2,cnt);
    if(check) cout << result_cnt+1 << '\n';
    else cout << -1 << '\n';
    return 0;
}