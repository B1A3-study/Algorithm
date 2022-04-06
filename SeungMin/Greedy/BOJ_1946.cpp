#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int testCase;
vector<pair<int, int> > slave;

bool compare(pair<int, int> a, pair<int, int> b) {return a.first > b.first;}

int main()
{
    int n;
    int g1, g2;
    cin >> testCase;
    while(testCase--){
        //서류1등은 무조건 통과
        int max_recruit=1;
        cin >> n;
        for(int i=0 ; i<n ; i++){
            cin >> g1 >> g2;
            slave.push_back(make_pair(g1, g2));
        }
        sort(slave.begin(),slave.end());

        int current=0;

        //2등부터 체크, 1등보다 면접점수 높은 사람 찾기
        //서류 등수 순으로 나열했기 때문에
        //1등 서류점수 낮은순으로 내려가다가 면접점수가 1등보다
        //높으면 채용댐
        for(int i=1 ; i<n ; i++){
            if(slave[current].second > slave[i].second){
                max_recruit++;
                current=i;
            }
        }
        cout << max_recruit << '\n';
        slave.clear();              
    }
    return 0;
}