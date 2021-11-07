import sys

target, n = map(int, sys.stdin.readline().split())
c = {}
for _ in range(n):
    cost, customer = map(int, sys.stdin.readline().split())
    c[customer] = cost
d = {}
for i in range(1, target + 1):
    a = []
    for cust in c.keys():
        for k in range(i - cust, i):
            if k >= 1:
                a.append(d[k] + c[cust])
            if k <= 0:
                a.append(c[cust])

    d[i] = min(a)
print(d[target])
