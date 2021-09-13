from collections import defaultdict, deque


def solution(n, d):
    """풀이: BFS 탐색으로 1번과 연결된 컴퓨터의 개수를 구한다."""
    visited = [1]  # 1번 방문
    trip = deque(d[1])  # 1번과 연결된 컴퓨터(노드)들을 탐색한다.

    while trip:  # 연결된 노드를 모두 탐색할 때까지 반복
        node = trip.popleft()
        if node not in visited:  # 아직 방문하지 않은 노드라면 방문
            visited.append(node)
            connected = d[node]
            for c in connected:  # 노드와 연결된 노드들 중 아직 방문하지 않은 노드들 trip에 추가
                if c not in visited:
                    trip.append(c)
    return len(visited) - 1


n = int(input())
t = int(input())
d = defaultdict(list)  # 기본 value값의 자료형이 list인 딕셔너리
for _ in range(t):
    k, v = input().split()
    d[int(k)].append(int(v))
    d[int(v)].append(int(k))
print(solution(n, d))
