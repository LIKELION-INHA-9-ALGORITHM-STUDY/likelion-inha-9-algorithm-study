def next_number(number, p):
	next = 0
	for n in str(number):
		next += int(n) ** p
	return next

def dfs(number, p, visited):
	if visited[number] == 2:
		return
	visited[number] += 1
	next = next_number(number, p)
	dfs(next, p, visited)

def solution():
	a, p = map(int, input().split())
	visited = [0] * 250000
	dfs(a, p, visited)
	
	count = 0
	for n in visited:
		if n == 1:
			count += 1
	print(count)

solution()