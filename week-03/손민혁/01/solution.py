def solution(array, commands):

    return [
        sorted(array[start - 1 : end])[target - 1] for start, end, target in commands
    ]
