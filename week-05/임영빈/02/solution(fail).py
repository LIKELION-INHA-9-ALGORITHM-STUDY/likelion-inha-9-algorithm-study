def solution(name):
	answer = 0
	for n in name:
		num = ord(n) - 65 #A의 아스키 코드 65
		rev_num = 26 - num #알파벳 개수 26
		answer += min(num, rev_num)
	if name[1] == 'A' or name[len(name) - 1] == 'A':
		answer -= 1
	return answer + len(name) - 1