def solution(nums):
	category = list()
	num_of_ponketmon = len(nums)
	for ponketmon in nums:
		if ponketmon not in category:
			category.append(ponketmon)
	num_of_category = len(category)
	return min(num_of_category, num_of_ponketmon//2)