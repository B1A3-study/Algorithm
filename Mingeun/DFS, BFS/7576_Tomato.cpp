#include <iostream>
#include <queue>

using namespace std;

int M, N, fin_depth;
int graph[1001][1001];
bool visited[1001][1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(){
    queue<pair<pair<int, int>, int> > q; // 좌표와 depth를 저장

    for (int i = 0; i < N; i++){
        for (int j = 0 ; j < M; j++){
            if (graph[i][j] == 1)   {
                visited[i][j] = true;
                q.push(make_pair(make_pair(i, j), 0));
            }
        }   //익은 토마토를 먼저 큐에 push
    }

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int depth = q.front().second;
        fin_depth = depth;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)     continue;
            if (visited[nx][ny] == true)                    continue;
            if (graph[nx][ny] == -1)                        continue;

            visited[nx][ny] = true;
            graph[nx][ny] = 1;
            q.push(make_pair(make_pair(nx, ny), depth + 1));
        }
    }
}

int main(){
    bool flag = true;
    cin >> M >> N;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 0)   flag = false; //다 익어있는 상태는 아님
            if (graph[i][j] == -1)  visited[i][j] = true; //걍 방문처리할래
        }
    }

    if (flag)   {
        cout << "0\n";
        return 0;
    }

    bfs();

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (visited[i][j] == false){
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << fin_depth << '\n';

    return 0;
}