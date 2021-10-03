import sys
def input(): return sys.stdin.readline()


sys.setrecursionlimit(10**6)  # 재귀 최대 깊이 /BOJ의 채점 서버에서 이 값은 1,000으로 되어 있
t = int(input())


def search(x, y):
    if x < 0 or y < 0 or x >= m or y >= n:  # 범위
        return
    if g[x][y] == 0:
        return
    else:
        g[x][y] = 0
        search(x, y - 1)  # 좌
        search(x, y + 1)  # 우
        search(x - 1, y)  # 상
        search(x + 1, y)  # 하


for _ in range(t):
    m, n, k = map(int, input().split(' '))
    g = [[0]*n for _ in range(m)]  # 땅덩어리
    for _ in range(k):
        x, y = map(int, input().split(' '))
        g[x][y] = 1
    cnt = 0
    for i in range(m):
        for j in range(n):
            if g[i][j] == 1:
                search(i, j)
                cnt += 1
    print(cnt)
