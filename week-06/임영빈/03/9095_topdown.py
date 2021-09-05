import sys

d_table = [0] * 11

# 29200kb, 72ms
def count_calc(n):
	if n == 1:
		return 1
	elif n == 2:
		return 2
	elif n == 3:
		return 4
	if d_table[n] != 0:
		return d_table[n]
	d_table[n] = count_calc(n - 1) + count_calc(n - 2) + count_calc(n - 3)
	return d_table[n]

def solution():
	read = lambda:sys.stdin.readline()
	testcase = int(read())
	numbers=[int(read()) for _ in range(testcase)]
	for n in numbers:
		print(count_calc(n))

solution()