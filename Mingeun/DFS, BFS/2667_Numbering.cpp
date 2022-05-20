#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt;
int graph[26][26];
bool visited[26][26];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool dfs(int x, int y){
    if (graph[x][y] == 0 || visited[x][y] == true)   return false;
    // cout << x << ' ' << y << endl;
    visited[x][y] = true;
    cnt++;
    // if (cnt < depth)      cnt = depth;

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= 0 || nx > N || ny <= 0 || ny > N)         continue;
        if (visited[nx][ny] == true || graph[x][y] == 0)      continue;
        
        dfs(nx, ny);
    }

    return true;
}

int main(){
    vector<int> nums;
    int res = 0;
    
    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cnt = 0;
            if (dfs(i, j) == true){
                nums.push_back(cnt);
                res++;
            }
        }
    }

    sort(nums.begin(), nums.end());

    cout << res << '\n';
    for (const auto& el: nums)  cout << el << '\n';

    return 0;
}