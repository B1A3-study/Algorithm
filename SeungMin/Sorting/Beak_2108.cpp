#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, input;
    int range, middle = 0, most_val, mean = 0;
    int most = -9999;
    int number[8001] = { 0, };
    bool not_first = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
        mean += input;
        //배열 범위를 그냥 4000더해놓고 위치 저장하고 나중에 빼기
        number[input + 4000]++;
    }
    sort(nums.begin(), nums.end());
    //최빈값 구하기
    for (int i = 0; i < 8001; i++) {
        //한번도 안나왔던 값이면 패스
        if (number[i] == 0) continue;
        //최빈값이 겹치는 경우
        if (number[i] == most) {
            //not_first가 true인경우 두번째로 큰 최빈값임
            //그러고 그다음 같은값가지는 최빈값 무시하기 위해
            //false로 변경
            if (not_first) {
                most_val = i - 4000;
                not_first = false;
            }
        }
        //최빈값 구하기, not_first는 제일 큰 최빈값인지 체크
        if (number[i] > most) {
            most = number[i];
            most_val = i - 4000;
            not_first = true;
        }
    }
    //중앙값 구하기
    middle = nums[nums.size() / 2];
    //산술평균 구하기
    mean = round((float)mean / n);
    //범위 구하기
    range = nums.back() - nums.front();
    //산술평균, 중앙값, 최빈값(겹치면 두번째로 작은수), 범위 출력
    cout << mean << '\n'
        << middle << '\n'
        << most_val << '\n'
        << range;
    return 0;
}