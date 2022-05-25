#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int N, L, R;
bool flag = true;

int graph[51][51];
int visited[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int startX, int startY, int number){
    queue<pair<int, int> > q;
    q.push(make_pair(startX, startY));
    visited[startX][startY] = number; 

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > N || ny <= 0 || ny > N)     continue; // 밖으로
            if (visited[nx][ny] == false){ //방문 가능한 곳일 때 
                int dist = abs(graph[x][y] - graph[nx][ny]);
                // cout << dist << endl;
                if (dist >= L && dist <= R) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = number; //받은 number로 이번 bfs동안 순회한 녀석들 대입
                }
            }
        }
    }
}

int main(){

    int res = -1;

    cin >> N >> L >> R;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> graph[i][j];
        }
    }

    while (flag){
        map<int, int> value;
        map<int, int> cnt;
        int number = 1;
        
        memset(visited, 0, sizeof(visited));

        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (visited[i][j] == 0) bfs(i, j, number); //visited 배열에서 다 bfs돌리고 맞는 number 배정
                number++;
            }
        }

        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                value[visited[i][j]] += graph[i][j]; 
                //map의 visited[i][j] key를 갖는 놈에다가 더함
                cnt[visited[i][j]]++;
                //cnt의 visited[i][j] key는 ++해서 몇 개인지 세주기
            }
        }

        int graph_bak[51][51];

        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                graph_bak[i][j] = graph[i][j];
            }
        }

        /* graph_bak에 graph 내용 백업 */

        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                graph[i][j] = value[visited[i][j]] / cnt[visited[i][j]];
            }
        }

        flag = false;

        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (graph_bak[i][j] != graph[i][j]){
                    flag = true;
                }
            }
        }
        
        res++;

    //         cout << "graph 출력" << endl;


    // for (int i = 1; i <= N; i++){
    //     for (int j = 1; j <= N; j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    //         cout << "graph_bak 출력" << endl;


    // for (int i = 1; i <= N; i++){
    //     for (int j = 1; j <= N; j++){
    //         cout << graph_bak[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << "visited 출력" << endl;

    // for (int i = 1; i <= N; i++){
    //     for (int j = 1; j <= N; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // for (map<int, int>::iterator it = value.begin(); it != value.end(); it++){
    //     cout << it -> first << ' ' << it -> second << endl;
    // }

    // cout << "cnt[1], value[1] 출력" << endl;

    // cout << cnt[1] << ' ' << value[1] << endl;
    }

    cout << res << '\n';

    return 0;
}