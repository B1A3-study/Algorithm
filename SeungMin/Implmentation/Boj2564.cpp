//백준2564번 경비원
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int col, row;
    cin >> col >> row;
    int n;
    cin >> n;
    int total = 2*row+2*col;
    vector<int> list;
    for(int i=0 ; i<=n ; i++){
        int x,y;
        cin >> x >> y;
        //각 위치에 따라 (0,0)에서 시계방향으로의 거리를 구한다
        switch(x){
            case 1: list.push_back(y); break;
            case 2: list.push_back(col+row+col-y); break;
            case 3: list.push_back(total-y); break;
            default: list.push_back(col+y); break; 
        }
    }
    int me = list.back();
    list.pop_back();
    int answer = 0;
    while(!list.empty()){
        //상점거리와 본인거리 중에 대소 비교
        //min(a,b) : 둘중에 짧은거 리턴
        //min(vector<int> a) : vector요소중에 젤 작은거 리턴
        int x = min(list.back(), me);
        int y = max(list.back(), me);
        //y-x : 길이가 더 긴거에서 짧은거 빼니까 단순히 본인과 상점과의 거리차이
        //나머지=total-(y-x)=total+x-y
        answer += min((total+x-y),(y-x));
        list.pop_back();
    }
    cout << answer;
    return 0;
}