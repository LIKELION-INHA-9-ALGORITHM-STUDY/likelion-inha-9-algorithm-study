from collections import defaultdict


def solution(n, computers):
    """BFS 한 번 탐색 => 하나의 네트워크 +1"""
    answer = 0
    nodes = range(n)

    # 딕셔너리에 컴퓨터 연결 정보 저장 / key : int, value : list
    d = defaultdict(list)
    for i in range(n):
        for j in range(n):
            if i != j and computers[i][j] == 1:
                d[i].append(j)

    # 모든 노드를 탐색할때까지 반복
    while nodes:
        visited = [nodes[0]]
        trip = d[nodes[0]]
        while trip:
            node = trip.pop(0)
            if node not in visited:
                visited.append(node)
                trip += d[node]

        nodes = list(set(nodes) - set(visited))  # 한 번의 BFS로 탐색한 노드들을 제거해주기
        answer += 1

    return answer
