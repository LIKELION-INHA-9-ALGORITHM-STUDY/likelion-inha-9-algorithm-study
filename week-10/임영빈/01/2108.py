import sys
read = sys.stdin.readline

#최빈값 반환 단 여러개 있을 시에 두번째로 작은값 반환
def return_mode(num_list):
	check = dict()
	for num in num_list:
		check[num] = check.get(num, 0) + 1
	max_num = max(check.values())
	li = list()
	for key, value in check.items():
		if value == max_num:
			li.append(key)
	if len(li) > 1 :
		return li[1]
	else :
		return li[0]

#return [평균, 중앙값, 최빈값, 범위]
def solution():
	n = int(read())
	num_list = list()
	for _ in range(n):
		temp = int(read())
		num_list.append(temp)
	num_list.sort()
	return (round(sum(num_list)/n), num_list[n//2], return_mode(num_list), num_list[-1] - num_list[0])

ans = solution()
for a in ans:
	print(a)