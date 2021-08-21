from heapq import heappop, heappush

def solution(operations):
	heap_max = list()
	heap_min = list()
	count = 0
	for operation in operations:
		key = operation[0]
		value = int(operation[2:])
		#case: push일 경우
		if key == "I":
			count += 1
			heappush(heap_min, value)
			heappush(heap_max, value * -1) # 최댓값 힙은 이런 방식으로 한 다음 pop할때 -1 다시 곱해준다.
		#case: pop일 경우
		else:
			count -= 1
			#예외 : 중간에 다 빠졌을때
			if count == 0:
				heap_min = []
				heap_max = []
			#예외 : 다빠졌는데도 더 뺄라할때 무시
			elif count < 0:
				count += 1
				continue
			#pop
			else:
				heappop(heap_min) if value < 0 else heappop(heap_max)
	try:
		return [heappop(heap_max)*-1, heappop(heap_min)]
	#예외 : 힙이 비어있으면 위에가 인덱스 오류나겠지
	except:
		return [0, 0]
	