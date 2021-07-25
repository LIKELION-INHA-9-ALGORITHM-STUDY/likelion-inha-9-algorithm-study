def solution(clothes):
	answer = 1
	hash_map = dict()
	for cloth in clothes:
		hash_map[cloth[1]] = hash_map.get(cloth[1], 0) + 1
	
	for i in hash_map.values():
		# +1은 각 착용하지 않은 경우의 수
		answer = answer * (i + 1)
	# -1은 아무것도 안입은 경우의 수
	return answer - 1