#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool compare(pair<int, int> x, pair<int, int> y){
    if (x.second == y.second){
        return x.first < y.first;
    }

    return x.second < y.second;
}

int main(){
    vector<pair<int, int> > v;
    cin >> N;

    for (int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;

        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), compare);

    int cnt = 0, last_end = 0;

    for (const auto &el: v){
        if (el.first >= last_end){
            last_end = el.second;
            cnt++;
        }
    }

    cout << cnt << '\n';


    return 0;
}