#include <iostream>
#include <vector>

using namespace std;

int arr[8];
bool visited[8];
vector<int> vec;
int N,M;

void dfs(int cnt)
{
    if(cnt == M){
        for(int i=0 ; i<vec.size() ; i++) {
            cout << vec[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0 ; i<N ; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        vec.push_back(arr[i]);
        dfs(cnt+1);
        vec.pop_back();
        visited[i] = false;
    }
}

int main()
{
    int cnt=0;
    cin >> N >> M;
    for(int i=0 ; i<N ; i++){
        arr[i] = i+1;
        visited[i] = false;
    }
    dfs(cnt);
    return 0;
}