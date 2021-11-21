def solution(numbers):
    return sum(filter(lambda n: n not in numbers, list(range(10))))