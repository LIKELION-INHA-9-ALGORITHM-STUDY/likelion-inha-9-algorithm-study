n = int(input())
cost = []
r, g, b = map(int, input().split())  # 첫번째 값 부터 채워줌
cost.append([r, g, b])

for i in range(1, n):
    """i번째의 색깔에 따라 i-1번째까지의 최소 비용을 각각 더해준다. => r,g,b 모든 경우의 색깔을 칠하는 경우의 최소 비용을 고려할 수 있음"""
    r, g, b = map(int, input().split())
    pR, pG, pB = cost[-1]  # i-1번째 집
    r = r + min(pB, pG)  # i번째 집의 색깔에 따라 i-1번째의 최소 비용을 더해줌
    g = g + min(pR, pB)
    b = b + min(pR, pG)
    cost.append([r, g, b])
print(min(cost[-1]))  # 마지막에 최솟값만 리턴
