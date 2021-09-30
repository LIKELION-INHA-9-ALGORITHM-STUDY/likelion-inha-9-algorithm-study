from collections import defaultdict

n = int(input())
color = defaultdict(dict)
for i in range(1, n + 1):
    r, g, b = map(int, input().split())
    color[i] = [(r, "r"), (g, "g"), (b, "b")]
    # {1: [(26, 'r'), (40, 'g'), (83, 'b')], 2: [(49, 'r'), (60, 'g'), (57, 'b')], 3: [(13, 'r'), (89, 'g'), (99, 'b')]}
cost = [(0, "n")] * (n + 1)


def paint(i, sandwich=False):
    """i번째 집의 비용과 색깔을 i-1번째 집의 색깔을 기준으로 구함"""
    for cos, col in sorted(color[i]):
        if col == cost[i - 1][1]:  # 최소 비용의 색깔이 이전의 집과 같은 색깔이면 다음 색으로
            continue
        if sandwich is True and col == cost[i + 1][1]:
            continue
        return (cos, col)


# 1,2 번째 집 비용 설정

cost[1] = min(color[1])
for i in range(2, n + 1):

    # cost1 - i-1번째 집 색깔을 고려해 i번째 비용 구하기
    cos1, col1 = paint(i)
    cost1 = cost[i - 2][0] + cost[i - 1][0] + cos1

    # cost2 - i번째 집의 색깔 구하기 -> i-1의 집 색깔 구하기
    cos2, col2 = sorted(color[i])[0]
    cost[i] = (cos2, col2)
    prev_cos, prev_col = paint(i - 1, sandwich=True)
    cost2 = cost[i - 2][0] + prev_cos + cos2

    if cost1 <= cost2:
        cost[i] = (cos1, col1)
    else:
        cost[i - 1] = (prev_cos, prev_col)
print(sum([cos for cos, col in cost]))
