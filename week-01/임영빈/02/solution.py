def solution(phone_book):
	hash_map = dict()
	for phone_num in phone_book:
		hash_map[phone_num] = len(phone_num)
	for phone_num in phone_book:
		num_len = len(phone_num)
		for i in range(num_len):
			temp = hash_map.get(phone_num[:i], False)
			if temp and num_len != temp:
				return False
	return True