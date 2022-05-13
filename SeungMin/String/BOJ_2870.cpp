#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
string temp = "";

bool compare(string a, string b)
{
    if(a.size() != b.size()) return a.size()<b.size();
    return a<b;    
}

void check()
{
    if(temp.length()){
        while(1){
            if(temp.length() && temp.front() == '0') temp.erase(temp.begin());
            else break;
        }
        if(temp.size() == 0) temp = "0";
        return;
    }
    return;
}

int main()
{
    vector<string> l;
    vector<string> nums;
    cin >> N;
    for(int i=0 ; i<N ; i++){
        string s;
        cin >> s;
        l.push_back(s);
    }
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<l[i].size() ; j++){
            if(l[i][j]-'0' >= 0 && l[i][j]-'0'<= 9){
                temp += l[i][j];
                if(j == l[i].size()-1){
                    check();
                    nums.push_back(temp);
                    temp = "";
                    continue;
                }
            }
            else{
                if(temp.size() > 0 ) {
                    check();
                    nums.push_back(temp);
                    temp = "";
                }
            }
        }
    }
    sort(nums.begin(),nums.end(),compare);
    for(auto x : nums) cout << x << '\n';

    return 0;
}