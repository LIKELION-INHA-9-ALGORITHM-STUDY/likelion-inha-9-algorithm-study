#이진 탐색 재귀함수
#arr에서 target이 있는지 찾아내고, 있으면 1, 없으면 0을 반환
def b_search_recur(arr, target, low, high):
	if low > high: # low > high면 재귀 탈출
		return 0
	
	middle = (low + high) // 2
	if arr[middle] == target: # target 찾으면 재귀 탈출
		return 1
	elif arr[middle] > target:
		return b_search_recur(arr, target, low, middle - 1)
	else:
		return b_search_recur(arr, target, middle + 1, high)

def solution():
	n_num = int(input())
	n_list = list(map(int, input().split(" ")))
	m_num = int(input())
	m_list = list(map(int, input().split(" ")))
	n_list.sort()
	for m in m_list:
		print(b_search_recur(n_list, m, 0, len(n_list) - 1))

solution()