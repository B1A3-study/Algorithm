#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M, X;
int d[1001];

vector<pair<int, int> > graph[10001];

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start, 0));
    d[start] = 0;

    while (!pq.empty()){
        int cur = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();

        if (dist > d[cur])      continue;

        for (int i = 0; i < graph[cur].size(); i++){
            int target = graph[cur][i].first;
            int cost = dist + graph[cur][i].second;

            if (cost < d[target]){
                d[target] = cost;
                pq.push(make_pair(target, -cost)); // 최소 힙이라 -
            }
        }
        
    }
}

int main(){
    int ref[1001];

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++){
        int start, end, dist;
        cin >> start >> end >> dist;

        graph[start].push_back(make_pair(end, dist));
    }

    fill(d, d + 1001, INT_MAX);

    dijkstra(X); 
    for (int i = 0; i <= 1000; i++){
        ref[i] = d[i];
    }

    int maxV = 0;

    for (int i = 1; i <= N; i++){
        fill(d, d + 1001, INT_MAX);
        dijkstra(i); //계속 d 배열 초기화하면서 i를 시작점으로 다익스트라
        int come = d[X]; //올 때는 새로 계산해서 i에서 X까지 가는 최단경로
        int go = ref[i]; //갈 때는 새로 계산할 필요 없이 X에서 i까지 가는 최단경로 ref꺼 씀

        maxV = max(maxV, come + go);
    }


    // for (int i = 1; i <= N; i++){
    //     if (d[i] != INT_MAX)    maxV = max(maxV, d[i]);
    // }

    cout << maxV << '\n';

    return 0;
}