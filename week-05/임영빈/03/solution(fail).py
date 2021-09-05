#8, 10케이스 시간초과

# 제거해야할 인덱스를 알려주는 함수
# 맨 앞부터 조회해서 앞보다 뒤가 더 큰 경우의 인덱스를 알려줌

def idx_will_remove(number, number_len):
	for i in range(0, number_len - 1):
		if number[i] < number[i + 1]:
			return i
	return number_len - 1

def solution(number, k):
	number = list(number)
	number_len = len(number)
	for _ in range(k):
		i = idx_will_remove(number, number_len)
		number = number[:i] + number[i+1:]
		number_len -= 1
	return "".join(number)
