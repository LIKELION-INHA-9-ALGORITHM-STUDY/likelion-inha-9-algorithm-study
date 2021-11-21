import sys
from collections import defaultdict

n = int(sys.stdin.readline())

g = defaultdict(list)  # 그래프 생성
for _ in range(n - 1):
    n1, n2, cost = list(map(int, sys.stdin.readline().split()))
    g[n1].append((n2, cost))  # n1 : [(n2,cost)]
    g[n2].append((n1, cost))  # n2 : [(n1,cost)]


def bfs(node):  # 어떤 노드를 기준으로 각 노드들을 탐색하며 거리 정보 리턴
    trip = [node]
    visited = []
    dist = [0] * (n + 1)
    while trip:
        t = trip.pop(0)
        visited.append(t)
        for i in range(len(g[t])):
            node, cost = g[t][i][0], g[t][i][1]
            if node not in visited:
                trip.append(node)
                dist[node] += cost
                dist[node] += dist[t]
    return dist


dist = bfs(1)
answer = bfs(dist.index(max(dist)))  # 가장 멀리 있는 노드를 구하고 다시 bfs
print(max(answer))  # 가장 긴 거리 = 그래프의 지름
