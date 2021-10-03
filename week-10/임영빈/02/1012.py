import sys
read = sys.stdin.readline
sys.setrecursionlimit(10000) #처음 알았네 재귀 깊이 제한 늘리기
dxy = ((1,0),(0,1),(-1,0),(0,-1))

def dfs(visit, r, c):
	if visit[r][c] == 0:
		return
	visit[r][c] = 0
	for i in range(4):
		next_r = r + dxy[i][0]
		next_c = c + dxy[i][1]
		if (next_r >= 0 and next_c>= 0 and next_r < len(visit) and next_c < len(visit[0])):
			dfs(visit, next_r, next_c)

def init():
	column, row, k = map(int, read().split())
	visit = [[0] * column for _ in range(row)]
	for _ in range(k):
		c, r = map(int, read().split())
		visit[r][c] = 1
	return visit

def solution():
	count = 0
	visit = init()
	for r in range(len(visit)):
		for c in range(len(visit[0])):
			if visit[r][c] == 1:
				count += 1
				dfs(visit, r, c)
	return count

for _ in range(int(read())):
	print(solution())