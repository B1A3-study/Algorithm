#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int A, B, sum = 0;

    cin >> A >> B;

    for (int i = 1; i <= B; i++){
        if (v.size() > 1000){
            break;
        }
        for (int j = 1; j <= i; j++){
            v.push_back(i);
        }
    }

    for (int i = A - 1; i <= B - 1; i++){
        sum += v[i];
    }
    
    cout << sum;

    return 0;
}