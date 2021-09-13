import sys

def dfs(start, dic, visited):
	visited[start] = 1
	for i in dic[start]:
		if visited[i] == 0:
			dfs(i, dic, visited)

def solution():
	read = sys.stdin.readline
	dic={}
	n = int(read())
	visited = [0] * (n + 1)
	for i in range(n):
		dic[i+1] = list()
	for _ in range(int(read())):
		a, b = map(int,read().split())
		dic[a].append(b)
		dic[b].append(a)	
	dfs(1, dic, visited)

	count = 0
	for n in visited:
		if n == 1:
			count += 1
	print(count - 1)

solution()