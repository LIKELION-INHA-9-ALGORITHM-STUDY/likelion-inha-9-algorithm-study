def b_search_recur(arr, target, low, high):
	if low >= high:
		return low
	middle = (low + high) // 2

	total = 0
	for t in arr:
		total += middle // t # 주어진 시간이 middle일 때 심사할 수 있는 최대 인원의 수
	if total >= target:
		return b_search_recur(arr, target, low, middle)
	else:
		return b_search_recur(arr, target, middle + 1, high)

def solution(n, times):
	return b_search_recur(times, n, 1, max(times) * n)

print(solution(6, [7, 10]))
