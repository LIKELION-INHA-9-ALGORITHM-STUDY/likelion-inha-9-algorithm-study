city_count = int(input())

graph = [None] * city_count

for i in range(city_count):
    graph[i] = list(map(int, input().split(" ")))

def dfs(graph, start, node, weight, visited, weights, min_case):
    if sum(weights) > min_case[0]:
        return

    new_visited = visited[:]
    new_visited[node] = True

    new_weights = weights + [weight]

    if all(new_visited):
        if graph[node][start] > 0:
            total = sum(new_weights) + graph[node][start]
            if min_case[0] > total:
                min_case[0] = total
        return

    for n, w in enumerate(graph[node]):
        if w == 0:
            continue # 길 없음

        if new_visited[n] == False:
            dfs(graph, start, n, w, new_visited, new_weights, min_case)


min_case = [float("inf")]

for city in range(city_count):
    dfs(graph, city, city, 0, [False] * city_count, [], min_case)

print(min_case[0])