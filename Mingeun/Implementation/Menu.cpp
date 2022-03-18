#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<string, int> x, pair<string, int> y){
    return x.second > y.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> combs;
    int max_value = -1;
    
    for (int i = 0; i < course.size(); i++){
        for (int j = 0; j < orders.size(); j++){      
            if (orders[j].size() < course[i]){
                continue;
            }
            
            sort(orders[j].begin(), orders[j].end());
            vector<bool> indexs(orders[j].size(), true);
            for (int k = 0; k < orders[j].size() - course[i]; k++){
                indexs[k] = false;
            }
        
            do {
                string patterns = "";
                for (int k = 0; k < indexs.size(); k++){
                    if (indexs[k] == true){
                        patterns += orders[j][k];
                    }
                }
                if (combs.find(patterns) != combs.end()){
                    combs[patterns]++;
                } else {
                    combs[patterns] = 1;
                }
            } while (next_permutation(indexs.begin(), indexs.end()));
        }
        
        if (combs.empty()){
            continue;
        }
    }
    
    vector<pair<string, int> > sortingCombs(combs.begin(), combs.end());
    sort(sortingCombs.begin(), sortingCombs.end(), compare);  
    
    for (int i = 0; i < course.size(); i++){
        for (int j = 0; j < sortingCombs.size(); j++){
            if (sortingCombs[j].second == 1){
                continue;
            }
            if (course[i] == sortingCombs[j].first.size()){
                if (max_value <= sortingCombs[j].second){
                    max_value = sortingCombs[j].second;
                    answer.push_back(sortingCombs[j].first);
                }
            }
        }
        max_value = -1;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}