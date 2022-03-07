#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[101];
bool visited[101];

//graph는 vector<int>의 전역 배열로 정의


//dfs 함수는 return형을 int로 정의해서 바이러스 전파시킨 컴퓨터 개수 셀 수 있게 함
int dfs(int start){
    int res = 1;
    visited[start] = true;

    for (int i = 0; i < graph[start].size(); i++){
        if (!visited[graph[start][i]]){
            //graph[start][i]를 방문하지 않았을 때
            visited[graph[start][i]] = true; //방문처리
            res += dfs(graph[start][i]);
            //재귀로 돌기
        }
    }
    
    return res;
}

int main(){
    int cnt, start, end; 
    cin >> N >> M;

    for (int i = 0; i < M; i++){
        scanf("%d %d", &start, &end);
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    //vector에 graph 입력받기 (양방향이라서 양쪽으로 입력함)

    cnt = dfs(1) - 1;
    //1번 그래프가 감염시킨거라서 빼고 카운팅함

    cout << cnt << '\n';

    return 0;
}