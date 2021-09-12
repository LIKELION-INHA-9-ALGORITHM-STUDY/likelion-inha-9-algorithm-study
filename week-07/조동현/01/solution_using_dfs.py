a, p = map(int, input().split(" "))

visited = [0] * (236196 + 1) # (9^5) * 4 + 1
def dfs(number, p, visited):
    if visited[number] == 2:
        return visited

    visited[number] += 1
    next_number = sum(map(lambda n: int(n) ** p, str(number)))
    return dfs(next_number, p, visited)

result = dfs(a, p, visited)
print(
    sum(filter(lambda n: n == 1, result))
)