def count_calc(num):
	d_table = [0] * (num + 1)
	for i in range(2, num + 1):
		temp1 = d_table[i - 1] + 1
		temp2 = (d_table[i // 3] + 1 if i%3 == 0 else 99999999)
		temp3 = (d_table[i // 2] + 1 if i%2 == 0 else 99999999)
		d_table[i] = min(temp1, temp2, temp3)
	return d_table[num]

def solution():
	n = int(input())
	print(count_calc(n))

solution()