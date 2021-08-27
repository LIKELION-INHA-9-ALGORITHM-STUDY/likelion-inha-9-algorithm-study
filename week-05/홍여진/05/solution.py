def solution(n, costs):
    answer = 0
    l = len(costs)
    all_lands = set()  # 연결해야할 모든 섬들
    for c in costs:
        all_lands.add(c[0])
        all_lands.add(c[1])
    connect_land = []  # 현재 연결된 섬들
    min_value = min([c[2] for c in costs])
    for c in costs:  # ... 다리건설비용이 min값인 섬들을 찾음
        if c[2] == min_value:
            connect_land.append(c[0])
            connect_land.append(c[1])
            costs.remove(c)
            answer += c[2]
            break

    state = 0
    for i in range(l):  # connect_land에 있는 섬과 connect_land에 없는 섬을 연결할 수 있는 costs를 구함. 그 중 min값을 찾아 connect_land에 계속 추가
        min_value = min([c[2] for c in costs if (c[0] in connect_land and not(
            c[1] in connect_land)) or (c[1] in connect_land and not(c[0] in connect_land))])
        for c in costs:
            if c[2] == min_value:
                connect_land.append(c[0])
                connect_land.append(c[1])
                answer += c[2]
                costs.remove(c)
            if set(connect_land) == all_lands:  # 모든 섬들이 연결됐다면 종료
                state = 1
        if state == 1:
            break
    return answer
