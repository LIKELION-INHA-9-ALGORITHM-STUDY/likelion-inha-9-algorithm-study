from heapq import heappush, heappop

def solution(scoville, K):
	count = 0
	heap = list()
	for num in scoville:
		heappush(heap,num)
	while (heap[0] < K):
		try:
			calc = heappop(heap) + heappop(heap) * 2
			heappush(heap, calc)
			count += 1
		except:
			return -1
	return count