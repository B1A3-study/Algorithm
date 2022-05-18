#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int n,m,x,answer;

vector<pair<int, int> > graph[1001];
int d[1001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push(make_pair(0,start));
    d[start]=0;

    while(!pq.empty()){
        int time = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now]<time) continue;
        for(int i=0; i<graph[now].size() ; i++){
            int tempTime = time+graph[now][i].second;
            if(tempTime < d[graph[now][i].first])
            {
                d[graph[now][i].first] = tempTime;
                pq.push(make_pair(tempTime,graph[now][i].first));
            }
        }
    }
}

int main()
{
    int tt[1001];
    cin >> n >> m >> x;
    for(int i=0 ; i<m ; i++){
        int a,b,t;
        cin >> a >> b >> t;
        graph[a].push_back(make_pair(b,t));
    }
    fill(d, d+1001, INF);

    //파티가는 최단경로
    for(int i=1 ; i<=n ; i++){
        dijkstra(i);
        i != x ? tt[i]=d[x] : tt[i]=-INF;
        for (int j = 1; j <= n; j++) d[j] = INF;
    }
    
    //각자 집가는 최단경로
    dijkstra(x);

    for(int i=1 ; i<=n ; i++){
        if(answer < d[i]+tt[i])
            answer = d[i]+tt[i];
    }
    cout << answer;
    return 0;
}