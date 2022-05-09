h, w = map(int, input().split())
height_list = list(map(int, input().split()))

max_idx = height_list.index(max(height_list))
answer = 0

# max_idx를 기준으로 좌측
left_temp = 0
for i in range(max_idx):
    if height_list[i] > left_temp:
        left_temp = height_list[i]
    answer += left_temp - height_list[i]

# max_idx를 기준으로 우측
right_temp = 0
for i in range(len(height_list)-1, max_idx, -1):
    if height_list[i] > right_temp:
        right_temp = height_list[i]
    answer += right_temp - height_list[i]

print(answer)