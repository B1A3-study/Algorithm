# 입력
w, h = map(int, input().split())
n = int(input())
store_location = [list(map(int, input().split())) for _ in range(n)]
my_location = list(map(int, input().split()))

answer = 0

if my_location[0] == 1:  # 북
    for d, l in store_location:
        if d == 1: # 북
            answer += abs(my_location[1] - l)
        elif d == 2: # 남
            left = my_location[1] + h + l
            right = (w - my_location[1]) + h + (w - l)
            answer += min(left, right)
        elif d == 3: # 서
            answer += my_location[1] + l
        elif d == 4: # 동
            answer += (w - my_location[1]) + l
elif my_location[0] == 2:  # 남
    for d, l in store_location:
        if d == 1:
            left = my_location[1] + h + l
            right = (w - my_location[1]) + h + (w - l)
            answer += min(left, right)
        elif d == 2:
            answer += abs(my_location[1] - l)
        elif d == 3:
            answer += my_location[1] + (h - l)
        elif d == 4:
            answer += (w - my_location[1]) + (h - l)
elif my_location[0] == 3:  # 서
    for d, l in store_location:
        if d == 1:
            answer += my_location[1] + l
        elif d == 2:
            answer += (h - my_location[1]) + l
        elif d == 3:
            answer += abs(my_location[1] - l)
        elif d == 4:
            left = my_location[1] + w + l
            right = (h - my_location[1]) + w + (h - l)
            answer += min(left, right)
elif my_location[0] == 4:  # 동
    for d, l in store_location:
        if d == 1:
            answer += my_location[1] + (w - l)
        elif d == 2:
            answer += (h - my_location[1]) + (w - l)
        elif d == 3:
            left = (h - my_location[1]) + w + (h - l)
            right = my_location[1] + w + l
            answer += min(left, right)
        elif d == 4:
            answer += abs(my_location[1] - l)

print(answer)