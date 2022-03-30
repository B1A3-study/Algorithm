#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int stone;

int main()
{
    cin >> stone;
    d[1] = 1;
    d[2] = 2;
    d[3] = 1;
    for(int i=4 ; i<=stone ; i++){
        d[i] = min(d[i-1]+1,d[i-3]+1);
    }
    if(d[stone]%2 == 0) cout << "CY" << '\n';
    else cout << "SK" << '\n';
    return 0;
}