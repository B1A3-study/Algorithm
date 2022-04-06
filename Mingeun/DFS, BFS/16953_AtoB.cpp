#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int A, B, res;
bool flag;

void bfs(int start){
    queue<pair<long long, int> > q;
    q.push(make_pair(start, 1));

    while(!q.empty()){
        long long x = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (x == B){
            flag = true;
            res = depth;
            break;
        }
        if (x * 2 <= B)         q.push(make_pair(x * 2, depth + 1));
        if (x * 10 + 1 <= B)    q.push(make_pair(x * 10 + 1, depth + 1));
    }
}

int main(){
    cin >> A >> B;
    bfs(A);

    if (!flag){
        cout << -1 << '\n';
    } else {
        cout << res << '\n'; 
    }



    return 0;
}