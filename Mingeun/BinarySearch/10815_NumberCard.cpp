#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, M, num;
    vector<int> x, y;
    
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> num;
        x.push_back(num);
    }

    sort(x.begin(), x.end());

    cin >> M;

    for (int i = 0; i < M; i++){
        cin >> num;
        y.push_back(num);
    }

    for (auto el: y){
        cout << binary_search(x.begin(), x.end(), el) << ' ';
    }

    cout << '\n';

    return 0;
}