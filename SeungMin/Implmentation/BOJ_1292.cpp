#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int sum=0;

int main()
{
    int a,b;
    int num=1;
    cin >> a >> b;
    while(1){
        for(int j=1 ; j<=num ; j++) {
            if(arr.size() == b) break;
            arr.push_back(num);
        }
        if(arr.size() == b) break;
        num++;
    }
    for(int i=a-1 ; i<=b-1 ; i++) sum += arr[i];
    cout << sum << '\n';
    return 0;
}