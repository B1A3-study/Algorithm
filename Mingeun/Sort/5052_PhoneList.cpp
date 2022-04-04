#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t, n;
    string tel;
    vector<string> list;
    vector<bool> flags;
    //일관성 성립 여부를 판단하는 flags 벡터 선언
    vector<vector<string> > lists;
    //2차원 벡터에 담음
    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n;
        list.clear();
        for (int j = 0; j < n; j++){
            cin >> tel;
            list.push_back(tel);
        }
        lists.push_back(list);
        flags.push_back(true);
    }

    for (int i = 0; i < t; i++){
        //사전 순으로 정렬
        sort(lists[i].begin(), lists[i].end());
    }

    for (int i = 0; i < t; i++){
        for (int j = 0; j < lists[i].size() - 1; j++){
            //j번째 전화번호가 j + 1 번째 전화번호의 substr(0 부터 j의 마지막 인덱스까지 자른 것)
            //이랑 같으면 일관성 있으니까 false 입력해줌
            if (lists[i][j] == lists[i][j + 1].substr(0, lists[i][j].size())){
                flags[i] = false;
            }
        }
    }

    for (auto el: flags){
        if (el) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}