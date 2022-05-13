#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
//백준 토마토 문제!!(BFS)
//BFS로 탐색하면서 1씩 증가시키기
queue<pair<int, int>> q;

int tomatoBox[1001][1001];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int N,M,day=0;

bool validLocation(int nx, int ny){
    return (nx >= 0 && nx < M && ny >= 0 && ny < N);
}

void bfs(void)
{
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];

            if(validLocation(nx, ny)==1 && tomatoBox[ny][nx]==0){
                tomatoBox[ny][nx] = tomatoBox[y][x]+1;
                q.push(make_pair(ny,nx));
            }
        }
    }
}

int main()
{
    int tomato;
    cin >> M >> N;
    for(int i=0 ; i<N ;i++){
        for(int j=0 ; j<M ;j++){
            cin >> tomato;
            tomatoBox[i][j] = tomato;
            if(tomato == 1) q.push(make_pair(i,j));
        }
    }
    bfs();

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<M ;j++){
            if(tomatoBox[i][j]==0){
                cout << -1;
                return 0;
            }
            if(day < tomatoBox[i][j]) day = tomatoBox[i][j];
        }
    }
    cout << day-1;
    return 0;
} 