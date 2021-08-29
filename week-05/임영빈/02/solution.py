# A나 Z에 더 가까운 수를 return 하는 함수
def near_alphabet_num(n):
	num = ord(n) - 65 #A의 아스키 코드 65
	rev_num = 26 - num #알파벳 개수 26
	return min(num, rev_num)

# (A가 시작되는 곳 까지의 길이 * 2) + (A가 끝나는 곳 ~ name의 끝 까지의 길이)를 반환
def move_count_except_a(name, i):
	name_len = len(name)
	idx_last_a = i + 1
	while idx_last_a < name_len and name[idx_last_a] == 'A':
		idx_last_a += 1
	return 2 * i + (name_len - idx_last_a)

def solution(name):
	topdown_count = 0
	leftright_count = len(name) - 1
	for i, n in enumerate(name):
		topdown_count += near_alphabet_num(n) #현재 위치에서 알파벳 맞추기
		leftright_count = min(leftright_count, move_count_except_a(name, i)) #더 이동횟수가 적은 count로 지정
	return topdown_count + leftright_count