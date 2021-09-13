import sys


def solution(n, d):
    res = []
    min_cost = sys.maxsize

    def dfs(i, visited, cost):
        if len(visited) == n:
            if cost + d[visited[-1]][visited[0]] < min_cost:
                cost = cost + d[visited[-1]][visited[0]]
                res.append(cost)
                return min_cost
            return

        for node in range(n):
            if d[i][node] != 0 and node not in visited and cost + d[i][node] < min_cost:
                dfs(node, visited + [node], cost + d[i][node])

        return

    for i in range(n):
        dfs(i, [i], 0)
        min_cost = min(res)

    return min_cost


n = int(input())
d = []
for _ in range(n):
    data = list(map(int, input().split()))
    d.append(data)

print(solution(n, d))
