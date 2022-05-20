from collections import deque
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(graph, i, j):
    n = len(graph)
    queue = deque([(i, j)])
    graph[i][j] = 0
    cnt = 1

    while queue:
        x, y = queue.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx, ny))
                cnt += 1
    return cnt

n = int(input())
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

answer = []
for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            answer.append(bfs(graph, i, j))

answer.sort()
print(len(answer))
for i in answer:
    print(i)