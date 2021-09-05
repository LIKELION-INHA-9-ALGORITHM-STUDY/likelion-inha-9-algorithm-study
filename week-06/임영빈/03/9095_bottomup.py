import sys

# 29200kb, 72ms
def count_calc(n):
	d_table = [0] * 11
	d_table[1] = 1
	d_table[2] = 2
	d_table[3] = 4
	for i in range(4, n + 1):
		d_table[i] = d_table[i - 1] + d_table[i - 2] + d_table[i - 3]
	return(d_table[n])

def solution():
	read = lambda:sys.stdin.readline()
	testcase = int(read())
	numbers=[int(read()) for _ in range(testcase)]
	for n in numbers:
		print(count_calc(n))

solution()