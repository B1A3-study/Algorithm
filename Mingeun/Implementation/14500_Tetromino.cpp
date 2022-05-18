#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int graph[501][501];
bool visited[501][501];
int N, M;
int maxV = -1;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int depth, int sum){ //T 모양 뺴고 백트래킹으로 탐색
    // cout << x << ' ' << y << endl;
    visited[x][y] = true;
    sum += graph[x][y];

    if (depth == 3){
        if (maxV < sum)      maxV = sum;
        return; //return 안 써서 멍청하게 시간 초과..
    }

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)     continue;
        if (visited[nx][ny] == true)                    continue;
        
        dfs(nx, ny, depth + 1, sum); 
        visited[nx][ny] = false;    // 백트래킹
    }
}

void Tsum(int x, int y){ //T 모양 - 십자 모양으로 다 더하고 하나씩 빼주기
    int sum = graph[x][y];
    int cnt = 1;

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)     continue;
        sum += graph[nx][ny];
        cnt++;
    }

    if (cnt < 4)        return; //이상한 모양임

    else if (cnt == 4){ //T자 모양 완성 -> 이거 안해서 계속 오답 나옴
        if (maxV < sum)     maxV = sum;
        return;
    }

    for (int i = 0; i < 4; i++){ //십자 모양이니까 하나씩 빼보기
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)     continue;
        if (maxV < (sum - graph[nx][ny]))  maxV = sum - graph[nx][ny];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            memset(visited, false, sizeof(visited));
            dfs(i, j, 0, 0);
            Tsum(i, j);
        }
    }

    cout << maxV << '\n';    


    return 0;
}