from collections import deque
import heapq


def solution(operations):
    heap = []
    for operation in operations:
        oper, v = operation.split(" ")  # oper: 명령어, v: 값
        if oper == "I":
            # 최소힙에 푸시
            heapq.heappush(heap, int(v))

        elif heap and oper == "D" and v == "-1":
            # 최소값 제거
            heapq.heappop(heap)

        elif heap and oper == "D" and v == "1":
            # deque로 변환 후 최대값 제거
            heap = deque(heap)
            heap.pop()
            heap = list(heap)

    if not heap:
        # 힙이 비었을 때
        return [0, 0]
    elif len(heap) == 1:
        # 힙에 원소가 하나만 남았을 때
        res = heap[0]
        return [res] * 2
    else:
        return [max(heap), min(heap)]
