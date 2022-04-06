A, B = map(int, input().split())

num = []
for i in range(B+1):
    for j in range(i):
        if len(num) == B:
            break
        num.append(i)

print(sum(num[A-1:B]))