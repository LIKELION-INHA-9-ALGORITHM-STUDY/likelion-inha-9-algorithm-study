def solution(participant, completion):
	hash_map = dict()
	for i in participant:
		hash_map[i] = hash_map.get(i, 0) + 1
	for j in completion:
		hash_map[j] -= 1
	for answer in hash_map:
		if hash_map[answer]:
			return answer