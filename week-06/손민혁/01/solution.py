def fibo(n):
    """풀이: 피보나치 값을 리스트에 추가한 후 마지막 값만 리턴"""
    res = [0, 1]
    if n == 0:
        return 0
    if n == 1:
        return 1
    for i in range(2, n + 1):
        f = res[i - 2] + res[i - 1]
        res.append(f)
    return res[-1]


n = int(input())
print(fibo(n))
