# python 에서 그냥 제공하는 in 써서 
def s_search(arr, num):
    if num in arr:
        return 1
    else:
        return 0

def solution():
	n_num = int(input())
	n_list = list(map(int, input().split(" ")))
	m_num = int(input())
	m_list = list(map(int, input().split(" ")))
	for m in m_list:
		print(s_search(n_list, m))

solution()