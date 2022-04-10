n = int(input())
have_list = list(map(int, input().split()))
m = int(input())
check_list = list(map(int, input().split()))

# 정렬
have_list.sort()

answer = []

# 이분 탐색
for num in check_list:
    start = 0
    end = len(have_list) - 1
    flag = False

    while start <= end:
        mid = (start + end) // 2

        if num > have_list[mid]:
            start = mid + 1
        elif num < have_list[mid]:
            end = mid - 1
        else:
            flag = True
            answer.append(1)
            break

    if not flag:
        answer.append(0)

# 정답 출력
for i in answer:
    print(i, end = ' ')