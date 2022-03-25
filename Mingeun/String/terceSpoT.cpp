#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> v;
    string s;
    while (getline(cin, s)){
        if (s == "END")  break;
        v.push_back(s);
    }

    for (string tmp : v){
        for (int i = tmp.size() - 1; i >= 0; i--){
            cout << tmp[i];
        }
        cout << endl;
    }



    return 0;
}