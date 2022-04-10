#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> arr,card;

bool compare(int a, int b){return a<b;}

// int binarySearch(vector<int> arr, int target, int start, int end)
// {
//     while(start<=end){
//         int mid = (start+end)/2;
//         if(arr[mid]==target) return 1;
//         else if(arr[mid] > target) end = mid-1;
//         else start = mid+1;
//     }
//     return 0;
// }

int main()
{
    cin >> N;
    for(int i=0; i<N ; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end(),compare);
    //for(const auto& a : arr) printf("%d ",a);

    cin >> M;
    for(int i=0 ; i<M ; i++){
        int num2;
        cin >> num2;
        card.push_back(num2);
    }
    for(const auto& c : card){
        if(binary_search(arr.begin(),arr.end(),c)) printf("%d ",1);
        else printf("%d ",0);
    }
    return 0;
}