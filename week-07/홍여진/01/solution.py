import sys
a, p = map(int, sys.stdin.readline().split())
d = [a]
while True:
    cur = d[-1]
    next = 0
    while cur:  # 수열계산
        next += ((cur % 10) ** p)
        cur //= 10
    if next in d:  # 반복되는 부분이 나왔을때 break
        sys.stdout.write(str(d.index(next)))
        break
    else:
        d.append(next)
