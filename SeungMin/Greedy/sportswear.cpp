#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check(n, 1);
    for (int i = 0; i < lost.size(); i++) check[lost[i] - 1]--;
    for (int i = 0; i < reserve.size(); i++) check[reserve[i] - 1]++;

    for (int i = 0; i < check.size(); i++) {
        if (check[i] == 0) {
            //마지막 사람이 앞사람한테 빌리기
            if (i == check.size() - 1 && check[i - 1] == 2) {
                check[i]++;
                check[i - 1]--;
            }
            //첫번째사람 제외하고 앞사람한테 빌리기
            else if (i != 0 && check[i - 1] == 2) {
                check[i]++;
                check[i - 1]--;
            }
            //뒷사람한테 빌리기, 뒤에 사람 먼저 체크하게 되면 앞사람이 있는지 체크 못할 수도
            else if (check[i + 1] == 2) {
                check[i]++;
                check[i + 1]--;
            }
        }
    }
    for (int i = 0; i < check.size(); i++) {
        if (check[i] != 0) answer++;
    }

    return answer;
}