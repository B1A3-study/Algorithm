#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int start = 0;

    for (int i = 0; i < number.size() - k; i++) {
        char maxNum = number[start];
        int maxAddr = start;

        for (int j = start; j <= k + i; j++) {
            if (maxNum < number[j]) {
                maxNum = number[j];
                maxAddr = j;
            }
        }
        start = maxAddr + 1;
        answer += maxNum;
    }

    return answer;
}