def solution(a, p):
    """연산을 통해 수열을 구하고 반복되는 수가 수열에 있다면 찾아서 인덱스 리턴 !!"""
    d = [0, a]
    i = 2
    while True:
        num = 0
        for n in str(d[i - 1]):
            n = int(n)
            num += n ** p
        if num in d:
            return d.index(num) - 1
        else:
            d.append(num)
        i += 1


a, p = input().split()
print(solution(int(a), int(p)))
