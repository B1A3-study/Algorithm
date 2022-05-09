#include <iostream>
#include <vector>

using namespace std;

bool graph[501][501];
int H, W;

int main(){
    vector<int> v;
    int num, total = 0;

    cin >> H >> W;

    for (int i = 0; i < W; i++){
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < W; i++){
        for (int j = 0; j < v[i]; j++){
            graph[j][i] = true;
        }
    }

    for (int i = 0; i < H; i++){
        int sum = 0, cnt = 0;
        bool start = false;
        
        for (int j = 0; j < W; j++){
            
            if (graph[i][j] == true && start == false){ //시작점 x인 상태에서 1 만남
                start = true; //시작점으로 세팅
            }
            else if (graph[i][j] == false && start == true){ //시작점 o인 상태에서 0 만남
                cnt++; //개수 늘려주기
            }
            else if (graph[i][j] == true && start == true){ //시작점 o인 상태에서 1 만남
                sum += cnt;
                cnt = 0;
            } 
        }
        total += sum;
    }

    cout << total << '\n';

    return 0;
}