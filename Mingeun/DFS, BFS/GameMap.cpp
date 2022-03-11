#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int answer = -1;

int visited[101][101];

void bfs(vector<vector<int> > maps, int startX, int startY){
    int cnt = 0;
    queue<pair<int, int> > q;
    
    visited[startX][startY] = 1;
    q.push(pair<int, int>(startX, startY));
    
    while(!q.empty()){
        pair<int, int> temp = q.front();
        int x = temp.first;
        int y = temp.second;
        q.pop();
        
        if (x == maps.size() - 1 && y == maps[0].size() - 1){
            answer = visited[x][y];
            break;
        }
        
        for (int i = 0; i < 4; i++){
            if (x + dx[i] < 0 || x + dx[i] > maps.size() - 1 || y + dy[i] < 0 || y + dy[i] > maps[0].size() - 1){ //밖으로 나가는 경우일 때
                continue;
            }
            
            if (!visited[x + dx[i]][y + dy[i]] && maps[x + dx[i]][y + dy[i]] == 1){
                visited[x + dx[i]][y + dy[i]] = visited[x][y] + 1;
                q.push(pair<int, int>(x + dx[i], y + dy[i]));
            }
        }
    }
    
}

int solution(vector<vector<int> > maps)
{
    
    bfs(maps, 0, 0);
    
    return answer;
}