def dfs(graph, v, visited):
    visited[v] = True
    for node, connected in enumerate(graph[v]):
        if node != v and connected == 1 and visited[node] == False:
            # 다음 노드가 자기자신이 아니며, 연결이 되어있고, 방문하지 않아야 탐색함.
            dfs(graph, node, visited)

    return visited

def solution(n, computers):
    visited = [False] * n
    count = 0
    while all(visited) == False:
        for n, v in enumerate(visited):
            if v == False:
                count += 1
                visited = dfs(computers, n, visited)

    return count