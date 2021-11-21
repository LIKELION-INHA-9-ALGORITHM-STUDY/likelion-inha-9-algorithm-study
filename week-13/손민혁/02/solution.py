import sys

n = int(sys.stdin.readline())

m = []
for _ in range(n):
    s, e = list(map(int, sys.stdin.readline().split()))
    m.append((s, e))
m.sort(key=lambda x: (x[1], x[0]))  # 회의 종료 기준 오름차순, 시작 기준 오름차순으로 정렬

answer = [m[0]]
for s, e in m[1:]:
    start, end = answer[-1]
    if s >= end:  # 회의의 시작 시간이 앞 회의의 종료 시간보다 크거나 같으면 가능
        answer.append((s, e))

print(len(answer))
