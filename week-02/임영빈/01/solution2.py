def solution_set(nums):
	num_of_ponketmon = len(nums)
	category = set(nums)
	num_of_category = len(category)
	return min(num_of_category, num_of_ponketmon//2)