//백준 : UCPC
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> UCPC;
bool check[4] = {false, };

bool checkUCPC(vector<char> ucpc){
    for(int i=0 ; i<ucpc.size() ; i++){
        //if(!(ucpc[i]=='U'||ucpc[i]=='C'||ucpc[i]=='P')) return false;

        if(ucpc[i]=='U'){
            check[0]=true;
        }
        else if(ucpc[i]=='P'){
            if(check[0]==true && check[1]==true) check[2]=true;
        }
        else if(ucpc[i]=='C'){
            if(check[0]==true && check[1] == true && check[2]==true) check[3]=true;
            else if(check[0] == true) check[1]=true;
        }
    }
    for(int i=0 ; i<sizeof(check) ; i++){
        if(check[i]==false) return false;
    }
    return true;
}

//공백이나 소문자면 무시 대문자면 push_back
int main()
{
    string stmt;
    getline(cin, stmt);
    for(int i=0 ; i<stmt.size() ; i++){
        if(stmt[i] >= 'A' && stmt[i] <= 'Z') UCPC.push_back(stmt[i]);
    }

    if(checkUCPC(UCPC)) cout << "I love UCPC" << '\n';
    else cout << "I hate UCPC" << '\n';

    return 0;
}