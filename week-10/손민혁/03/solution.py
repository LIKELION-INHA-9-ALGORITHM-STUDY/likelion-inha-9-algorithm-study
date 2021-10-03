h = {}
n, m = map(int, input().split())
for _ in range(n):
    id, pwd = map(str, input().split())
    h[id] = pwd
for _ in range(m):
    site = input()
    print(h[site])
