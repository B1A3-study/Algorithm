from itertools import combinations
 
N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
 
house = []
chicken = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            house.append((i, j))
        elif board[i][j] == 2:
            chicken.append((i, j))
 
min_dist = float('inf')
for ch in combinations(chicken, M):
    sum = 0
    for h in house:
        sum += min([abs(h[0]-i[0]) + abs(h[1]-i[1]) for i in ch])
    if sum < min_dist:
        min_dist = sum
 
print(min_dist)