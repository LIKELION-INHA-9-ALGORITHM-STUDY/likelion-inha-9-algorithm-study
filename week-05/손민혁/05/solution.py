from collections import defaultdict


def solution(n, costs):
    """
    최소비용 다리 건설을 위한 조건
    1. 섬들이 연결되어 있지 않음
    2. 연길된 섬들이 삼각형을 이루면 안됨(순환X)

    위 2가지를 만족하면 다리를 건설한다.
    """

    def is_triange(cost):
        """
        설명: 다리를 지었을 때 순환(삼각형)이 생기는지 검사
        방법: 섬1과 연결된 섬들, 섬2와 연결된 섬들 중 중복된 섬이 있으면 순환임
        """
        if len(visited[cost[0]] - visited[cost[1]]) != len(visited[cost[0]]):
            return True
        return False

    def is_linked(i1, i2, visit):
        """
        설명: 섬1 과 섬2가 연결되어 있는지 검사
        방법: 재귀를 통해 섬1부터 각 섬과 연결된 섬들을 탐색하기 시작해서 섬2와 연결되어 있는지 확인한 후, 연결되어 있으면 res == 1 이 된다.
        """
        res = 0
        if i2 in visited[i1]:
            return True

        for island in visited[i1]:
            if island not in visit:
                visit.add(island)
                res += is_linked(island, i2, visit)

        if visit == set(visited):
            return False

        return res

    islands = set(range(n))  # 0,1,2 ... n
    visited = defaultdict(set)  # 기본 value가 set인 딕셔너리
    answer = 0
    costs = sorted(costs, key=lambda x: x[2])  # 다리건설비용 기준 오름차순 정렬

    for cost in costs:
        if not is_triange(cost) and not is_linked(cost[0], cost[1], {cost[0]}):
            visited[cost[0]].add(cost[1])
            visited[cost[1]].add(cost[0])
            answer += cost[2]

    return answer
