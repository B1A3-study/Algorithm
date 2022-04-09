#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);

    int N, M, num;
    int arr[100001];


    cin >> N;
    
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cin >> M;

    for (int i = 0; i < M; i++){
        cin >> num;
        cout << binary_search(arr, arr + N, num) << '\n';
    }

    return 0;
}