#include <iostream>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    int pos = -1;
    bool flag = false;

    if (str.find("U") != string:: npos){
        pos = str.find("U");
    } 
    if (pos != -1){
        str = str.substr(pos);
        if (str.find("C") != string:: npos){
            pos = str.find("C");
            str = str.substr(pos);

            if (str.find("P") != string:: npos){
                pos = str.find("P");
                str = str.substr(pos);

                if (str.find("C") != string:: npos){

                    flag = true;
                }
            }
        }
    }

    
    if (flag)   cout << "I love UCPC" << '\n';
    else cout << "I hate UCPC" << '\n';
    

    return 0;
}