#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n + 2, 0);
    
    for (int i = 0; i < lost.size(); i++){
        student[i]--;
    }
    
    for (int i = 0; i < reserve.size(); i++){
        student[i]++;
    }
    
    for (int i = 0; i <= n; i++){
        if (student[i] < 0){
            if (student[i - 1] == 1){
                student[i]++;
                student[i - 1]--;
            }
            else if (student[i + 1] == 1){
                student[i]++;
                student[i + 1]--;
            }
        }
    }
    
    for (int i = 1; i <= n;i++){
        if (student[i] >= 0)
            answer++;
    }
    
    return answer;
}