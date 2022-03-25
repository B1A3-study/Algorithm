from collections import defaultdict
n = int(input())
num = []

for _ in range(n):
    num.append(int(input()))

num.sort()

print(round(sum(num) / n))
print(num[n // 2])
num_dict = defaultdict(int)
for i in num:
    num_dict[i] += 1
num_dict = dict(sorted(num_dict.items(), key=lambda x: x[1], reverse=True)) # 딕셔너리 정렬
temp_mode = []
count = list(num_dict.values())
for k, v in num_dict.items():
    if v == count[0]:
        temp_mode.append(k)
if len(temp_mode) != 1:
    temp_mode.sort()
    print(temp_mode[1])
else:
    print(max(temp_mode))
print(max(num) - min(num))
