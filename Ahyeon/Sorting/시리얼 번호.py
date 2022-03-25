n = int(input())
num_list = []

# 입력
for _ in range(n):
    num = input()
    temp = 0
    for i in num:
        if i.isdigit():
            temp += int(i)
    num_list.append((num, temp))

num_list.sort(key= lambda x: (len(x[0]), x[1], x[0]))

# 출력
for num in num_list:
    print(num[0])