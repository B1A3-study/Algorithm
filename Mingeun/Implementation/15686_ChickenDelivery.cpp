#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

int getDist(pair<int, int> x, pair<int, int> y){
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main(){
    vector<vector<int> > v;
    vector<int> tmp;
    vector<pair<int, int> > chickens, houses;
    vector<bool> ch_indexs;
    int num, minD = 1000000, minTotalD = 0, minV = 10000000;

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        tmp.clear();
        for (int j = 0; j < N; j++){
            cin >> num;
            tmp.push_back(num);
        }
        v.push_back(tmp);
        
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (v[i][j] == 2){
                chickens.push_back(make_pair(i, j));
            }
            if (v[i][j] == 1){
                houses.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < M; i++){
        ch_indexs.push_back(true);
    }

    for (int i = 0; i < chickens.size() - M; i++){
        ch_indexs.push_back(false);
    }

    sort(ch_indexs.begin(), ch_indexs.end());

    do {
        vector<pair<int, int> > temp = chickens;

        for (int i = 0; i < ch_indexs.size(); i++){
            if (ch_indexs[i] == false){
                temp[i].first = -1;
                temp[i].second = -1;
            }
        } //치킨집 중 M개만 순서없이 선택(조합)한 뒤 선택받지 못한 애들은 0으로 만듦

        minTotalD = 0;
        for (auto h: houses){
            minD = 1000000;
            for (auto ch: temp){
                if (ch.first != -1 && ch.second != -1){
                    // cout << "check" << endl;
                    if (minD > getDist(h, ch)){
                        minD = getDist(h, ch);
                    }
                }
                // cout << h.first << ' ' << h.second << ' ' << ch.first << ' ' << ch.second << ' ' << minD << ' ' << getDist(h, ch) << endl;
            }
            minTotalD += minD;
        }
        if (minV > minTotalD){
            minV = minTotalD;
        }

    } while (next_permutation(ch_indexs.begin(), ch_indexs.end()));

    cout << minV << '\n';

    return 0;
}