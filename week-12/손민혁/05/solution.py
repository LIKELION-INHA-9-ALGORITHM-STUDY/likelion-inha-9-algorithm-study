import sys

n = int(sys.stdin.readline())
g = []
for i in range(n):
    row = list(map(int, sys.stdin.readline().split()))
    g.append(row)
    if 9 in row:
        cur_y, cur_x = i, row.index(9)  # 아기상어 위치

size = 2
trip = [(cur_y, cur_x, 0)]  # 탐색할 위치의 y,x,거리
visited = []
g[cur_y][cur_x] = 0  # 아기 상어 위치값 9 -> 0
fish = 0  # 먹은 물고기 수
distance = 0  # 총 이동 거리
fishes = []  # 최단 거리 내 먹을 수 있는 물고기들

while trip:
    trip = list(set(trip))  # 중복값 제거
    for _ in range(len(trip)):
        t = trip.pop(0)
        y, x, d = t
        visited.append((y, x))

        d += 1  # 거리 +1
        if 0 <= y - 1 < n:  # n 칸 제한
            if 0 <= g[y - 1][x] <= size:  # 통과 or 물고기 먹기 가능
                if (y - 1, x) not in visited:
                    trip.append((y - 1, x, d))  # 통과 가능

                    if 0 < g[y - 1][x] < size:
                        fishes.append((y - 1, x, d))  # 물고기 먹기 가능

        if 0 <= x - 1 < n:
            if 0 <= g[y][x - 1] <= size:
                if (y, x - 1) not in visited:
                    trip.append((y, x - 1, d))

                    if 0 < g[y][x - 1] < size:
                        fishes.append((y, x - 1, d))

        if 0 <= x + 1 < n:
            if 0 <= g[y][x + 1] <= size:
                if (y, x + 1) not in visited:
                    trip.append((y, x + 1, d))

                    if 0 < g[y][x + 1] < size:
                        fishes.append((y, x + 1, d))

        if 0 <= y + 1 < n:
            if 0 <= g[y + 1][x] <= size:
                if (y + 1, x) not in visited:
                    trip.append((y + 1, x, d))

                    if 0 < g[y + 1][x] < size:
                        fishes.append((y + 1, x, d))

    if len(fishes) != 0:
        if len(fishes) == 1:  # 최단 거리 내 물고기가 한 마리면 바로 이동
            cur_y, cur_x = fishes[0][0], fishes[0][1]
        else:
            fishes = sorted(
                fishes, key=lambda x: (x[0] - cur_y, x[1] - cur_x)
            )  # 물고기가 여러마리면 현재 위치 기준 가장 위, 왼쪽으로 이동
            cur_y, cur_x = fishes[0][0], fishes[0][1]

        trip = [(cur_y, cur_x, 0)]
        visited = []
        g[cur_y][cur_x] = 0
        fishes = []
        fish += 1
        if fish == size:  # 먹은 물고기 수와 상어의 크기가 같아지면 크기 +1
            size += 1
            fish = 0
        distance += d
        d = 0


print(distance)
