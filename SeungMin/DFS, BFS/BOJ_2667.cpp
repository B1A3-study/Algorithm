#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,cnt=0,h=0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int graph[26][26];
bool visited[26][26]={false,};
vector<int> house;

bool validLocation(int nx, int ny){
    return (nx >= 0 && nx < N && ny >= 0 && ny < N);
}

void dfs(int x, int y)
{
    if(graph[x][y]==1 && visited[x][y]==false){
        h++;
        visited[x][y]=true;
        for(int i=0 ; i<4 ; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(validLocation(nx, ny) && graph[nx][ny]==1){
                dfs(nx,ny);
            }
        }
    }
    else{
        return;
    }
}

int main()
{
    cin >> N;
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            scanf("%1d",&graph[i][j]);
        }
    }
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            h=0;
            if(graph[i][j]==1 && visited[i][j]==false){
                dfs(i,j);
                cnt++;
                house.push_back(h);
            }
        }
    }

    cout << cnt << '\n';
    sort(house.begin(),house.end());
    for(const auto& x : house) printf("%d\n",x);
    return 0;
}