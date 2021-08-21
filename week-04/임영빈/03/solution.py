def solution(brown, yellow):
	total = brown + yellow
	for i in range(1, total//2 + 1):
		if total % i == 0:
			row = total // i
			col = i
			if row + col == brown//2 + 2:
				return [row, col]