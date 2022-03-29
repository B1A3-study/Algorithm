#include <iostream>
#include <vector>

using namespace std;

int r, c, N;

int main(){
    vector<pair<int, int> > v;
    vector<int> x, y;
    int d, pos, sum = 0;
    cin >> r >> c;
    cin >> N;

    for (int i = 0; i < N + 1; i++){
        cin >> d >> pos;
        v.push_back(make_pair(d, pos)); //위치 정보 입력
    }

    for (auto el: v){ //시계방향으로 가기
        switch(el.first){
            case 1: //북
            x.push_back(el.second);
            break;

            case 2: //남
            x.push_back(el.second * -1 + r + c + r);
            break;

            case 3: //서
            x.push_back(el.second * -1 + r + c + r + c);
            break;
            
            case 4: //동
            x.push_back(el.second + r);
            break;
        }
    }

    for (auto el: v){ //반시계방향으로 가기
        switch(el.first){
            case 1: //북
            y.push_back(el.second * -1 + r);
            break;

            case 2: //남
            y.push_back(el.second + r + c);
            break;

            case 3: //서
            y.push_back(el.second + r);
            break;

            case 4: //동
            y.push_back(el.second * -1 + r + c + r + c);
            break;
        }
    }

    for (int i = 0; i < N; i++){
        sum += min(abs(x[N] - x[i]), abs(y[N] - y[i]));
    }

    cout << sum << '\n';

    return 0;
}