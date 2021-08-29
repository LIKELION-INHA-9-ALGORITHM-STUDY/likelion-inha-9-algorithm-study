from collections import deque

# 정렬된 무게 사람들 중에 무거운 사람 기준으로 태울건데
# 가장 가벼운 사람이랑 무게를 합쳤을때 limit를 안넘으면 가벼운 친구도 빠이
def pop_edge(deq, limit):
	if deq[0] + deq[-1] <= limit and len(deq) != 1:
		deq.popleft()
	deq.pop()

def solution(people, limit):
	deq = deque(sorted(people))
	count = 0
	while len(deq) > 0:
		pop_edge(deq, limit)
		count += 1
	return count