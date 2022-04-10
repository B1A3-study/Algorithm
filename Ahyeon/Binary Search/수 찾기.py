n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

a.sort()

for i in b:
    start = 0
    end = len(a) - 1
    flag = 0

    while start <= end:
        mid = (start + end) // 2

        if i > a[mid]:
            start = mid + 1
        elif i < a[mid]:
            end = mid - 1
        else:
            flag = 1
            break

    if flag == 1:
        print(1)
    else:
        print(0)