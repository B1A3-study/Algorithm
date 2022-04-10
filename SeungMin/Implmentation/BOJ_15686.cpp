#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>

using namespace std;

int N,M;
//map<pair<int,int>, int> house;
vector<pair<int, int> > house,chicken;
int result=10e5;

bool compare(int a, int b){return a<b;}

void Combination(vector<pair<int,int>> ch, int index, int depth)
{
    //치킨집들중에 M개 골라서 도시의 치킨거리 최솟값 만들기
    if(depth == M)//M개 골랐으면?
    {
        int res=0;
        //for(const auto& x : ch) printf("경우의수\n%d %d\n",x.first,x.second);
        //printf("==============\n");
        for(const auto& h : house){
            int temp=101;
            for(const auto& c : ch){
                int t = abs(h.first-c.first)+abs(h.second-c.second);
                if(t < temp) temp = t;
            }
            //printf("집의 치킨거리 : %d\n",temp);
            res += temp;
        }
        if(res < result) result = res;
        //printf("도시의 치킨거리 : %d\n==========\n",res);
        return;
    }
    else
    {
        for(int i=index ; i<chicken.size() ; i++){
            ch.push_back(chicken[i]);
            Combination(ch, i+1, depth+1);
            ch.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0 ; i<N; i++){
        for(int j=0 ; j<N ; j++){
            int n;
            cin >> n;
            if(n == 1) house.push_back(make_pair(i+1,j+1));
            else if(n == 2) chicken.push_back((make_pair(i+1,j+1)));
        }
    }
    
    vector<pair<int, int> > ch(M);
    ch.clear();
    Combination(ch, 0, 0);

    cout << result << '\n';
}