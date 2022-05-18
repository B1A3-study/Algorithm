#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 // 무한으로 10억 설정

using namespace std;

// 노드 개수 N, 간선 개수 M
int N, M, X;

vector<pair<int, int>> graph[1001];

int d[1001];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist) continue;
        for(int i = 0; i < graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(void){
    int max = 0;
    cin >> N >> M >> X;
    int *dx = new int[N+1];

    for(int i = 0; i < M; i++){
        int x, y ,z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
    }
    fill(d, d + 1001, INF);
    dijkstra(X);
    for(int i = 1; i<= N; i++){
        dx[i] = d[i];
    }
    for(int i = 1; i<= N; i++){
        if(i == X)continue;
        fill(d, d + 1001, INF);
        dijkstra(i);
        if(max < dx[i] + d[X]){
            max = dx[i] + d[X];
        }
    }
    cout << max;
    return 0;
}