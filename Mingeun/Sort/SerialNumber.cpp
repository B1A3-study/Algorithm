    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    bool compare(string x, string y){
    int sumX = 0, sumY = 0;
    //길이가 다를 때
    if (x.size() != y.size())   return x.size() < y.size();

    for (int i = 0; i < x.size(); i++){
        if (x[i] >= '0' && x[i] <= '9')     sumX += x[i] - '0';
        if (y[i] >= '0' && y[i] <= '9')     sumY += y[i] - '0';
    }

    if (sumX != sumY)   return sumX < sumY;

    return x < y;
    }

    int main(){
    int N;
    vector<string> v;
    string strBuff;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> strBuff;
        v.push_back(strBuff);
    }

    sort(v.begin(), v.end(), compare);

    for (auto el: v){
        cout << el << '\n';
    }

    return 0;
    }