#include <iostream>
#include <vector>

using namespace std;

int H,W;
vector<int> Wlist;
vector<vector<int> > wall;
int water=0;

int main()
{
    scanf("%d %d",&H,&W);
    for(int i=0 ; i<W ; i++){
        int vW;
        cin >> vW;
        Wlist.push_back(vW);
    }
    // for(auto x : Wlist) cout << x << '\n';

    for(int i=0 ; i<H ; i++){
        vector<int> level;
        for(int j=0 ; j<W ; j++){
            if(Wlist[j]>0){
                level.push_back(1);
                Wlist[j]--;
            }
            else{
                level.push_back(0);
            }
        }
        wall.push_back(level);        
    }
    for(int i=0 ; i<wall.size() ; i++){
        bool v=false;
        int start=0,end=0;
        for(int j=0 ; j<wall[i].size() ; j++){
            if(wall[i][j]==1 && v==false){
                start = j;
                v=true;
            }
            else if(wall[i][j]==1 && v==true) end = j;
        }
        if(end == 0) continue;
        for(int k=start ; k<=end ; k++){
            // printf("%d %d\n",i,k);
            if(wall[i][k]==0) water++;
        }
    }
    cout << water;
    return 0;
}