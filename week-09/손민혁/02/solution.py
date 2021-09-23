from collections import defaultdict
import sys

m, n, b = list(map(int, input().split()))
g = defaultdict(int)  # dict{ 좌표 높이 : 같은 높이의 개수 } / ex) {0 : 11, 1 : 1}
for i in range(m):
    floor = list(map(int, input().split()))
    for f in floor:
        g[f] += 1

max_h = max(g)  # 최고 높이
min_h = min(g)  # 최저 높이

min_cost, h = sys.maxsize, max_h
cost = 0
while max_h >= min_h:  # 최대 높이부터 최소 높이까지 모두 탐색하며 최소 비용 찾기

    demand = sum([(max_h - h) * g[h] for h in g])  # 최대 높이 기준으로 평탄화 시키기 위해 필요한 블록의 개수

    if b >= demand and cost + demand < min_cost:
        # 인벤토리의 블록의 수(b)가 충분하고 쌓는 비용까지 고려해서 최소 비용보다 적으면 최소 비용과 높이 갱신
        min_cost, h = cost + demand, max_h

    # 최대 층의 블록을 제거하고 인벤토리에 추가, 비용 갱신
    cost += g[max_h] * 2
    b += g[max_h]
    g[max_h - 1] += g[max_h]
    del g[max_h]
    max_h -= 1

    if len(g) == 1 and cost < min_cost:
        # 딕셔너리의 개수가 1이면 땅이 고른 상태 => 비용을 최저 비용과 비교하고 갱신
        min_cost, h = cost, max_h

print(min_cost, h)
