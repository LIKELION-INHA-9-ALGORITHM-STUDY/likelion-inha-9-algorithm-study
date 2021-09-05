d_table = [0] * 100

# 29200kb, 72ms
def fibonacci(num):
	d_table[1] = 1
	d_table[2] = 1
	for i in range(3, num + 1):
		d_table[i] = d_table[i - 1] + d_table[i - 2]
	return d_table[num]


def solution():
	n = int(input())
	print(fibonacci(n))

solution()