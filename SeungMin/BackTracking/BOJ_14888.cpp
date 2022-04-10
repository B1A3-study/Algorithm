#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long int max_result=-10e9, min_result=10e9;
vector<int> arr;
vector<bool> visited;
//연산자 조합
vector<char> cal, c;

void dfs(int cnt)
{
    if(cnt == cal.size()){
        long long int temp=arr[0]; //cout << arr[0];
        for(int i=0 ; i<c.size() ; i++){
            //printf(" %c %d",c[i],arr[i+1]);
            if(c[i] == '+') temp += arr[i+1];
            else if(c[i] == '-') temp -= arr[i+1];
            else if(c[i] == '*') temp *= arr[i+1];
            else if(c[i] == '/') temp /= arr[i+1];
        }
        //cout << '\n';
        if(temp > max_result) max_result = temp;
        if(temp < min_result) min_result = temp;
        return;
    }
    for(int i=0 ; i<cal.size() ; i++){
        if(visited[i]) continue;
        visited[i]=true;
        c.push_back(cal[i]);
        dfs(cnt+1);
        c.pop_back();
        visited[i] = false;
    }
}

int main()
{
    cin >> N;
    for(int i=0 ; i<N ; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    //연산자 저장
    for(int i=0 ; i<4 ; i++){
        int op_count;
        cin >> op_count;
        for(int j=0 ; j<op_count ; j++){
            if(i==0) cal.push_back('+');
            else if(i==1) cal.push_back('-');
            else if(i==2) cal.push_back('*');
            else cal.push_back('/');
            visited.push_back(false);
        }
    }
    //for(const auto& x : cal) printf("%c ",x);
    //cout << '\n';
    dfs(0);
    printf("%lld\n%lld",max_result,min_result);
    return 0;
}