#include <iostream>
#include <string>

using namespace std;

string str[101];
string result[10000];

void sort(int index){
    for(int i = 0; i < index - 1; i++){
        for(int j = 0; j < index - 1 - i; j++){
            if(result[j].length() > result[j + 1].length()){
                swap(result[j], result[j + 1]);
            }
            else if(result[j].length() == result[j + 1].length() && result[j] > result[j + 1]){
                swap(result[j], result[j + 1]);
            }
        }
    }
}

int main(void){
    int N, index = 0;;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < str[i].length(); j++){
            if(str[i][j] >= '0' && str[i][j] <= '9'){
                if(!result[index].empty() && result[index].front() == '0'){
                    result[index].clear();
                }
                result[index].push_back(str[i][j]);
            }
            else{
                if(!result[index].empty()){
                    index++;
                }
            }
        }
        if(!result[index].empty()){
            index++;
        }
    }
    sort(index);
    for(int i = 0; i < index; i++){
        cout << result[i] << endl;
    }
}