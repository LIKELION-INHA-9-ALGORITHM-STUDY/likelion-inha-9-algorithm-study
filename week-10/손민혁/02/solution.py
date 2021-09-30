import sys

sys.setrecursionlimit(10 ** 6)  # 재귀의 깊이 제한 늘리기 !!!

""" 풀이: 배추가 심어져 있는 경우만 입력을 받고, 이를 모두 지워주기 위해 dfs를 통해 상,하,좌,우를 모두 탐색하며 지운다."""


def dfs(g, i, j):
    if 0 <= i - 1 <= m - 1 and (i - 1, j) in g:  # 좌
        del g[(i - 1, j)]
        dfs(g, i - 1, j)
    if 0 <= i + 1 <= m - 1 and (i + 1, j) in g:  # 우
        del g[(i + 1, j)]
        dfs(g, i + 1, j)
    if 0 <= j - 1 <= n - 1 and (i, j - 1) in g:  # 하
        del g[(i, j - 1)]
        dfs(g, i, j - 1)
    if 0 <= j + 1 <= n - 1 and (i, j + 1) in g:  # 상
        del g[(i, j + 1)]
        dfs(g, i, j + 1)


t = int(input())
for _ in range(t):
    m, n, k = map(int, input().split())
    g = {}
    for _ in range(k):
        a, b = map(int, input().split())
        g[(a, b)] = 1

    cnt = 0
    while len(g) != 0:
        i, j = g.popitem()[0]
        dfs(g, i, j)
        cnt += 1
    print(cnt)
