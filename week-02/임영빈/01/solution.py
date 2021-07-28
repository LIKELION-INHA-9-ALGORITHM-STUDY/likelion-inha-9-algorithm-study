# (nums[]) =>{
#	nums배열에서 총개수와 종류개수 구해서
#	return (min(총개수/2, 종류개수))
# }

def solution(nums):
	category = list()
	num_of_ponketmon = len(nums)
	for ponketmon in nums:
		if ponketmon not in category:
			category.append(ponketmon)
	num_of_category = len(category)
	return min(num_of_category, num_of_ponketmon//2)

def solution_set(nums):
	num_of_ponketmon = len(nums)
	category = set(nums)
	num_of_category = len(category)
	return min(num_of_category, num_of_ponketmon//2)