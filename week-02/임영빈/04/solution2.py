from collections import deque

# deque에서 지정 값보다 더 작을 때의 idx를 반환
def find_idx_from_deque(price, time_prices):
    idx = 0
    for time_price in time_prices:
        idx += 1
        if time_price < price:
            break
    return idx

def solution(prices):
	answer = list()
	time_prices = deque(prices)
	# 만약 prices가 [1,2,3,2,3]이었다면
	# find_idx_from_deque(1, [2,3,2,3])이렇게 들어감, 그 담에는
	# find_idx_from_deque(2, [3,2,3])
	while(time_prices):
		idx = find_idx_from_deque(time_prices.popleft(), time_prices)
		answer.append(idx)
	return answer