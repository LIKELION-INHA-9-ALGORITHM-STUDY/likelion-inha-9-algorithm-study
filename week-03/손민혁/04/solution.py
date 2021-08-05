import heapq


def solution(scoville, K):

    answer = 0

    # heapq 모듈은 최소힙을 지원한다
    heap = []
    for s in scoville:
        heapq.heappush(heap, s)

    # s1 : 가장 안매운 음식의 스코빌 / s2: 두 번째로 안매운 음식의 스코빌
    while len(heap) >= 2:
        s1 = heapq.heappop(heap)

        if s1 >= K:
            # 가장 안매운 음식 스코빌이 K이상이면 바로 종료
            return answer

        s2 = heapq.heappop(heap)
        new_s = s1 + (s2 * 2)
        answer += 1
        heapq.heappush(heap, new_s)

    if heapq.heappop(heap) < K:
        # 마지막에 남은 음식의 스코빌이 K보다 작으면 -1 리턴
        return -1

    return answer
