def dfs(numbers, current, target, hit_count):
    if len(numbers) == 0:
        return hit_count + (current == target)

    n = numbers[-1]

    negative_case = dfs(numbers[:-1], current - n, target, hit_count)
    positive_case = dfs(numbers[:-1], current + n, target, hit_count)

    return negative_case + positive_case

def solution(numbers, target):
    return dfs(numbers, 0, target, 0)