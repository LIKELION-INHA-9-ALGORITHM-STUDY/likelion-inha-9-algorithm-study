d_table = [0] * 100

# 29200kb, 72ms
def fibonacci(num):
	if num == 1 or num == 2:
		return 1
	if d_table[num] != 0:
		return (d_table[num])
	d_table[num] = fibonacci(num - 1) + fibonacci(num - 2)
	return d_table[num]

def solution():
	n = int(input())
	print(fibonacci(n))

solution()
