n = int(input())
m = int(input())
graph = [[] * n for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

count = 0
visited = [False] * (n + 1)


def dfs(start):
    global count
    visited[start] = True
    for i in graph[start]:  # dfs 재귀를 이용해 네트워크로 연결된 모든 컴퓨터 검사.
        if visited[i] == False:
            count += 1
            dfs(i)


dfs(1)
print(count)
