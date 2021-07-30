from collections import deque

# deque에서 지정 값보다 더 작을 때의 idx를 반환
def find_idx_from_deque(target, deq):
    idx = 0
    for d in deq:
        idx += 1
        if d < target:
            break
    return idx

def solution(prices):
	answer = list()
	prices = deque(prices)
	# 만약 prices가 [1,2,3,1,3]이었다면
	# find_idx_from_deque(1, [2,3,1,3])이렇게 들어가서 idx=4반환, 그 담에는
	# find_idx_from_deque(2, [3,1,3]) 이렇게 들어가서 idx=2반환
	while(prices):
		idx = find_idx_from_deque(prices.popleft(), prices)
		answer.append(idx)
	return answer