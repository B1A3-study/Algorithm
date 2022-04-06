def dfs():
    if len(s) == M:
        print(*s)
        return

    for i in range(1, N + 1):
        if i in s:
            continue
        s.append(i)
        dfs()
        s.pop()

N, M = map(int, input().split())
s = []
dfs()