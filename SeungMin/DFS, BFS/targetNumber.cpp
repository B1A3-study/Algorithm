#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;

void dfs(vector<int> numbers, int target, int sum, int depth) {
    if (depth == numbers.size()) {
        if (sum == target) cnt++;
        return;
    }
    dfs(numbers, target, sum + numbers[depth], depth + 1);
    dfs(numbers, target, sum - numbers[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    cout << cnt << endl;
    return cnt;
}

int main(void) {
    vector<int> a = { 1, 1, 1, 1, 1 };
    solution(a, 3);
    return 0;
}