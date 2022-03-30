#include <iostream>

using namespace std;

int N, cnt;
bool flag;

int graph[101][101];
int temp[101][101];
bool visited[101][101];

int dx[] = {0, -1, 0, 1}; //동남서북
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y){
    if (visited[x][y] || temp[x][y] <= 0)  return;

    visited[x][y] = true; //방문 처리
    flag = true; //방문 가능하므로 영역임을 나타는 flag를 true로 만듦

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;
        //밖으로 나갔을 때

        if (temp[nx][ny] <= 0){ //물에 잠겼을 때
            visited[nx][ny] = true; //방문 처리 후
            continue; //재귀는 안하기
        }

        if (!visited[nx][ny]){
            dfs(nx, ny); //그 영역 계속 탐색
        }
    }
}

int main(){
    int num, maxV = -1, max_cnt = 0;

    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> graph[i][j];
            if (maxV < graph[i][j])  maxV = graph[i][j]; //높이의 최댓값 계산
        }
    }

    for (int i = 0; i <= maxV; i++){ // 비 안 오는 경우 고려 해서 i 시작값 0
        cnt = 0; //cnt 초기화
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                temp[j][k] = graph[j][k] - i; //비가 온걸 temp에 반영
                visited[j][k] = false;  //visited 배열 초기화
            }
        }
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                flag = 0; //flag 초기화
                dfs(j, k); //모든 점에 대해 탐색
                if (flag) cnt++; //영역을 찾았을 때 마다 영역 카운트 늘리기
            }
        }

        if (max_cnt < cnt)  max_cnt = cnt; //맥스 카운트보다 현재 영역 카운트가 더 크면 반영
    }

    cout << max_cnt << '\n';

    return 0;
}