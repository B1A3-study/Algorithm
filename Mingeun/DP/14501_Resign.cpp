#include <iostream>
#include <algorithm>

using namespace std;


int d[16];

int main(){
    pair<int, int> data[16];
    int t, p, index, N;

    cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> t >> p;
        data[i] = make_pair(t, p);
    }

    for (int i = N; i > 0; i--){
        index = i + data[i].first;
        if (index > N + 1){ //기간이 N보다 커서 못하니까 skip
            d[i] = d[i + 1];
        }
        else {
            d[i] = max(d[i + 1], d[index] + data[i].second);
        }
    }

    cout << d[1] << '\n';

    return 0;
}