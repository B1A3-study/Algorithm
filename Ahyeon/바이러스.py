def dfs(n, start, graph, visited):
    visited[start] = True # 방문 노드 True로 변경
    for i in range(n+1):
        if not visited[i] and graph[start][i] == 1:
            result.append(i) # 방문하지 않음 & 연결된 노드 result 배열에 추가
            dfs(n, i, graph, visited)
    return len(result)

n = int(input())
m = int(input())
graph = [[0]*(n+1) for _ in range(n+1)] # 그래프 저장

for i in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

start = 1
result = []
visited = [False] * (n+1) # 방문 여부 체크
print(dfs(n, 1, graph, visited))