def sort(a,b):
	if a > b:
		temp = a
		a = b
		b = temp
	return(a,b)

def solution(n,a,b):
	answer = 1
	a,b = sort(a,b)
	while(True):
		if b - a < 2 and b//2 == a//2:
			break
		a = a//2 + a % 2 
		b = b//2 + b % 2
		answer += 1
	return answer