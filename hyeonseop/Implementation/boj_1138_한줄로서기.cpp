#include<iostream>

using namespace std;

int N; // 사람 수
int m[11]; // 입력 값을 저장할 배열
int result[11]; // 결과 값을 저장할 배열

int main(void){
    // 입력 코드
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> m[i];
    }

    // 구현 코드
    // 키가 작은 사람부터 결과 배열에 입력된다
    // 결과 배열이 0이면 자기보다 큰 사람이 들어가야
    // 되기 때문에 그 자리는 비워둔다.
    // 비워둔 자리의 개수와 입력 값이 일치하면서
    // 결과 배열이 비어있으면 그 자리가 자신의 자리이다
    for(int i = 1; i <= N; i++){
        int index = 0;
        for(int j = 1; j <= N; j++){
            if(index == m[i] && result[j] == 0){
                result[j] = i;
                break;
            }
            if(result[j] == 0){
                index++;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << result[i] << " ";
    }
}
