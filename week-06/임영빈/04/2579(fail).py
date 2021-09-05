import sys

def count_calc(lists):
	count = 0
	lists_len = len(lists)
	d_table = [0] * lists_len
	d_table[0] = lists[0]

	for i in range(1, lists_len - 1):
		count += 1
		if d_table[i] != 0 :
			continue
		if count < 3:
			if lists[i + 1] > lists[i]:
				d_table[i] = d_table[i - 1]
				d_table[i + 1] = d_table[i] + lists[i + 1]
				count = 1
			else:
				d_table[i] = d_table[i - 1] + lists[i]
				count += 1
		else:
			d_table[i] = d_table[i - 1]
			count = 0
	d_table[lists_len - 1] = d_table[lists_len - 2] + lists[lists_len - 1]
	return d_table[lists_len - 1]

def solution():
	read = lambda:sys.stdin.readline()
	stairs_count = int(read())
	stairs = [int(read()) for _ in range(stairs_count)]
	print(count_calc(stairs))

solution()