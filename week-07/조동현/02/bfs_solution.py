from collections import defaultdict, deque

computer_count = int(input())
edge_count = int(input())

graph = defaultdict(set)

for _ in range(edge_count):
    n1, n2 = map(int, input().split(" "))
    graph[n1].add(n2)
    graph[n2].add(n1)

visited = [False] * (computer_count + 1)

def bfs(graph, node, visited):
    deq = deque()
    deq.append(node)

    while len(deq) > 0:
        current_node = deq.popleft()
        for neighbor_node in graph[current_node]:
            if visited[neighbor_node] == False:
                deq.append(neighbor_node)
                visited[neighbor_node] = True

    return visited

print(sum(bfs(graph, 1, visited)) - 1)