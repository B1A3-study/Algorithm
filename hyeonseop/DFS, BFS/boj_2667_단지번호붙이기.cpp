#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, cnt = 0;

int num[1000];
int graph[26][26];
bool visited[26][26];

queue<pair<int, int>> q;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(){
    int num = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        num++;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
            if(graph[nx][ny] == 1 && visited[nx][ny] == false){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return num;
}

int main(void){
    // 입력 받기
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(graph[i][j] == 1 && visited[i][j] == false){
                visited[i][j] = true;
                q.push({i, j});
                num[cnt] = bfs();
                cnt++;
            }
        }
    }
    sort(num, num+cnt);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++){
        cout << num[i] << endl;
    }
}