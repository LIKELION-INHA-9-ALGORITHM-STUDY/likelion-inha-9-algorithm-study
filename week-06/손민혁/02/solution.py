def solution(n):
    """딕셔너리에 최소 계산 결과를 저장하고 필요 시 불러와 사용한다"""
    cache = {}
    cache[1] = 0

    for i in range(2, n + 1):
        cache[i] = cache[i - 1] + 1  # 1을 빼는 연산
        if i % 3 == 0:
            # 3으로 나누는 연산
            cache[i] = min(cache[i], cache[i // 3] + 1)
        if i % 2 == 0:
            # 2로 나누는 연산
            cache[i] = min(cache[i], cache[i // 2] + 1)
    return cache[n]


n = int(input())
print(solution(n))
