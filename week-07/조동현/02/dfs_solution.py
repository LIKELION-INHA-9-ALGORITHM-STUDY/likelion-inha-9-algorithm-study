from collections import defaultdict

computer_count = int(input())
edge_count = int(input())

graph = defaultdict(set)

for _ in range(edge_count):
    n1, n2 = map(int, input().split(" "))
    graph[n1].add(n2)
    graph[n2].add(n1)

visited = [False] * (computer_count + 1)

def dfs(graph, node, visited):
    visited[node] = True
    for neighbor_node in graph[node]:
        if visited[neighbor_node] == False:
            dfs(graph, neighbor_node, visited)
    return visited

print(sum(dfs(graph, 1, visited)) - 1)
