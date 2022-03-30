#include <iostream>

using namespace std;

int main(){
    int s[1001] = {0, };
    int N;

    cin >> N;

    s[1] = 1;
    s[2] = 2;
    s[3] = 1;

    for (int i = 4; i <= N; i++){
        if (s[i - 1] != 0){
            s[i] = s[i - 1] + 1;
        }

        if (s[i - 3] != 0){
            s[i] = s[i - 3] + 1;
        }
    }

    if (s[N] % 2 == 0) cout << "CY" << '\n';
    if (s[N] % 2 != 0) cout << "SK" << '\n';

    return 0;
}