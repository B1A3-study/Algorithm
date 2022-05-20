#include <iostream>
#include <vector>

using namespace std;

int n;
int answer[11]={0,};

int main()
{
    vector<pair<int,int>> people;

    cin >> n;
    for(int i=0 ; i<n ; i++ )
    {
        int l;
        cin >> l;
        people.push_back(make_pair(i+1,l));
    }

    for(int i=0 ; i<n ; i++)
    {
        int count=0;
        for(int j=1 ; j<=n ; j++)
        {
            if(count==people[i].second && answer[j]==0){
                answer[j] = people[i].first;
                break;
            }
            else
                if(answer[j]==0) count++;
        }

    }
    for(int i=1 ; i<=n ; i++) cout << answer[i] << ' ';
    return 0;
}