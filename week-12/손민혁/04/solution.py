import sys
import heapq

n, target = list(map(int, sys.stdin.readline().split()))

values = []
for _ in range(n):
    value = int(sys.stdin.readline())
    heapq.heappush(values, -1 * value)  # max heap

cnt = 0  # 동전 개수
while target != 0:
    v = -1 * heapq.heappop(values)
    num = target // v  # 몫은 필요한 동전의 수
    if num >= 1:  # 동전의 수가 1 이상이여야함
        cnt += num
        target = target % v  # 남은 돈

print(cnt)
