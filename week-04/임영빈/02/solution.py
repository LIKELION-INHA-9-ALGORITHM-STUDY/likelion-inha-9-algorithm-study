global_set = set()

#소수인지 체크하는 함수
def is_prime(num):
	if num == 0 or num == 1:
		return 0
	for i in range(2, num//2 + 1):
		if num % i == 0:
			return 0
	return 1

#재귀함수 만약 두번째 인자가 12345라면 
#level0 : "2345", "1345", "1245", "1235", "1234"
#level1-2345 : "345", "245", "235", "234"
#level1-1345 : "345", "145", "135", "134"
#level1-1245 : "245", "145", "125", "124"
#level1-1235 : "235", "135", "125", "123"
#level1-1234 : "234", "134", "124", "123"
#level2 ...
#level3 ...
# 이런식으로 두번째 인자에 값이 들어갑니다.
def recurs_combinations(str1, str2):
	try : num = int(str1)
	except : num = 0

	if is_prime(num):
		global_set.add(num)

	for i in range(len(str2)):
		recurs_combinations(str1 + str2[i], str2[0:i] + str2[i + 1:])

def solution(numbers):
	recurs_combinations("", numbers)
	answer = len(global_set)
	return answer