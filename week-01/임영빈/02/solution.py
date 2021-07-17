def solution(phone_book):
	hash_map = dict()
	for phone_num in phone_book:
		hash_map[phone_num] = len(phone_num)
	for phone_num in phone_book:
		temp_num = ""
		for num in phone_num:
			temp_num += num
			temp = hash_map.get(temp_num, False)
			if temp and len(phone_num) != temp:
				return False
	return True