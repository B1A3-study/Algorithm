# 서류 순위를 기준으로 오름차순 정렬해 준 다음, 면접의 순위만 놓고 비교하기

import sys

T = int(input())

for _ in range(T):
    cnt = 1
    people = []

    N = int(input())
    for _ in range(N):
        Paper, Interview = map(int, sys.stdin.readline().split())
        people.append([Paper, Interview])

    people.sort() # 서류 기준 오름차순 정렬
    temp = people[0][1] # 면접 등수 비교

    for i in range(1, N):
        if temp > people[i][1]:
            cnt += 1
            temp = people[i][1]

    print(cnt)