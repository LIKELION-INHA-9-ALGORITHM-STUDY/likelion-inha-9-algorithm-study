def solution(nums):
    choice = len(nums) / 2
    remove_duplicated = set(nums)

    if len(remove_duplicated) <= choice:
        return len(remove_duplicated)
    else:
        return choice