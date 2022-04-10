#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N=5,M;
vector<int> arr, test;

bool compare(int a, int b) {return a < b;}

int binarySearch(vector<int>& arr, int target, int start, int end)
{
    //printf("target : %d\n",target);
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid]==target) return 1;
        else if(arr[mid] > target) end = mid-1;
        else start = mid+1;
    }
    return 0;
}

int main()
{
    cin >> N;
    for(int i=0 ; i<N ; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    //오름차순 정렬
    sort(arr.begin(),arr.end(),compare);
    //for(const auto& num : arr) cout << num << ' ';

    cin >> M;
    for(int i=0 ; i<M ; i++){
        int tnum;
        cin >> tnum;
        test.push_back(tnum);
    }
    for(const auto& a : test){
        cout << binarySearch(arr, a, 0, arr.size()-1) << '\n';
    }
    return 0;
}