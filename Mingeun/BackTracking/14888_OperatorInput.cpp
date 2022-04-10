#include <iostream>

using namespace std;

int N;
int nums[12];
int opr[4];

long long maxV = -1000000000010;
long long minV = 1000000000010;

void dfs(int result, int depth){
    if (depth == N - 1){
        if (result > maxV){
            maxV = result;
        }
        if (result < minV){
            minV = result;
        }
    }

    for (int i = 0; i < 4; i++){
        if (opr[i] > 0){
            opr[i]--;
            switch(i){
                case 0:
                    dfs(result + nums[depth + 1], depth + 1);
                    break;
                case 1:
                    dfs(result - nums[depth + 1], depth + 1);
                    break;
                case 2:
                    dfs(result * nums[depth + 1], depth + 1);
                    break;
                case 3:
                    dfs(result / nums[depth + 1], depth + 1);
                    break;        
            }
            opr[i]++;
        }
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++){
        cin >> opr[i];
    }

    dfs(nums[0], 0);

    cout << maxV << '\n' << minV << '\n';

    return 0;
}