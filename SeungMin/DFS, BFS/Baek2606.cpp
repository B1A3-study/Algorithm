#include <bits/stdc++.h>

using namespace std;

int com, connect;
int graph[101][101];
int visited[101];
int virus = -1;

void dfs(int com, int now) {
    visited[now] = 1;
    virus++;
    for (int i = 1; i < com + 1; i++) {
        if (visited[i] == 1) //방문했으면 패스
            continue;
        if (graph[now][i] == 0) //연결성 없으면 패스
            continue;
        dfs(com, i);
    }
}

int main(void) {
    cin >> com;
    cin >> connect;
    int a, b;

    for (int i = 0; i < connect; i++) {
        cin >> a >> b;
        //양방향성 연결
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    dfs(com, 1);

    cout << virus;
    return 0;
}