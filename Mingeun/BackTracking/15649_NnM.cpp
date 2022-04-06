#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int nums[9];
bool visited[9];

void dfs(int depth){
    if (depth == M){
        for (int i = 0; i < M; i++){
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++){
        if (!visited[i]){ // 방문한 적이 없을 때
            visited[i] = true; // 방문 처리
            nums[depth] = i; // depth번째의 수는 현재 내가 1부터 N까지 중에서 고른 수
            dfs(depth + 1); // 다음 depth 탐색
            visited[i] = false; // dfs로 인해 한 줄 탐색이 끝났으므로 visited 초기화
        }
    }
}

int main(){
    vector<int> v;
    cin >> N >> M;
    
    dfs(0);

    return 0;
}