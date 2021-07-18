def solution(clothes):
	answer = 1
	hash_map = dict()
	for cloth in clothes:
		hash_map[cloth[1]] = hash_map.get(cloth[1], 0) + 1
	for i in hash_map.values():
		answer = answer * (i + 1)
	return answer - 1