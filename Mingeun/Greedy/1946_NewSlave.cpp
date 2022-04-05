#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
    //오름차순
}

int main(){
    int T, N, x, y;
    cin >> T;

    vector<vector<pair<int, int> > > lists;
    vector<pair<int, int> > list;

    for (int i = 0; i < T; i++){
        cin >> N;
        list.clear();
        for (int j = 0; j < N; j++){
            cin >> x >> y;
            list.push_back(make_pair(x, y));
        }
        lists.push_back(list);
    }

    for (int i = 0; i < T; i++){
        sort(lists[i].begin(), lists[i].end(), compare);
    }

    for (auto vv: lists){
        int minV = 100001;
        int cnt = 0;
        for (auto v: vv){
            if (minV > v.second){
                minV = v.second;
                cnt++;
            } 
        }
        cout << cnt << '\n';
    }

    return 0;
}