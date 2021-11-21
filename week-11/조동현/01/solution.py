def solution(arr):
    ret = []

    prev = None
    for n in arr:
        if n != prev: ret.append(n)
        prev = n

    return ret