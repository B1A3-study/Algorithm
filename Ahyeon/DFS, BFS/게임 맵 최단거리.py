from collections import deque

def solution(maps):
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    n = len(maps)
    m = len(maps[0])

    visited = [[False] * m for _ in range(n)] # 방문했는지 체크

    # [0, 0]에서 시작
    visited[0][0] = True
    queue = deque([(0, 0)])

    while queue:
        x, y = queue.popleft()

        # 갈 수 있는 방향 체크
        for i, j in zip(dx, dy):
            nx = x + i
            ny = y + j

            # 좌표가 음수이거나, [n, m] 길이를 벗어나는 경우
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            else:
                # 벽이 없고 & 방문하지 않은 곳일 경우
                if maps[nx][ny] != 0 and visited[nx][ny] == False:
                    queue.append((nx, ny)) # 다음으로 가기 위해 큐에 저장
                    # 방문한 경우 +1 추가
                    visited[nx][ny] = visited[x][y] + 1

    # 상대 팀 진영에 도착할 수 없을 경우
    if visited[n - 1][m - 1] == False:
        return -1
    else:
        return visited[n - 1][m - 1]