#include <iostream>
#include <algorithm>

using namespace std;

int n;
int ares[101][101];
bool isSafe[101][101] = {true,};

bool dfs(int x, int y){
    //주어진 범위 벗어나면 바로 종료
    if(x <= -1 || x >= n || y <= -1 || y >= n) return false;
    //현재 노드가 안전하다면
    if(isSafe[x][y] == true){
        isSafe[x][y] = false;//해당노드 방문처리
        //상하좌우 재귀적으로 호출
        dfs(x-1,y);
        dfs(x,y-1);
        dfs(x+1,y);
        dfs(x,y+1);
        return true;
    }
    return false;
}

int main()
{
    int max_height=1, max_safe=0;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> ares[i][j];
            //입력 받을 때 최대 높이 저장해놓기
            if(ares[i][j] >= max_height) max_height = ares[i][j];
        }
    }
    //비가 오지 않는 경우 생각하기....
    for(int i=0 ; i<=max_height ; i++){
        int temp_safe=0;
        fill(&isSafe[0][0],&isSafe[n][n], true);
        //높이마다 물에 잠긴 구역 체크
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<n ; k++){
                //특정 높이 이하는 false로 변환
                if(ares[j][k] <= i) isSafe[j][k] = false;
            }
        }
        //해당높이에서 안전구역 개수 계산
        for(int a=0 ; a<n ; a++){
            for(int b=0 ; b<n ; b++){
                if(dfs(a,b)) temp_safe += 1;
            }
        }
        //최대안전구역 체크
        if(max_safe < temp_safe) max_safe = temp_safe;
    }
    cout << max_safe << '\n';
    return 0;
}