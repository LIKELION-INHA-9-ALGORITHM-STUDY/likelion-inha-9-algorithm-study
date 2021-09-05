def solution(steps):
    """
    풀이: 점화식에 따라 캐시에 각 계단별 최댓값을 저장한다.
    점화식: i단계까지 최댓값 = max(i-2단계까지 최댓값 + 현재 값, i-3단계까지 최댓값 + i-1단계의 값 + 현재 값) 단, i-3 >= 0 일때만 가능
    """
    if len(steps) >= 3:
        cache = [0] * (len(steps))
        cache[0] = steps[0]
        cache[1] = steps[0] + steps[1]
        cache[2] = max(steps[0] + steps[2], steps[1] + steps[2])
        for i in range(3, len(steps)):
            cache[i] = max(
                cache[i - 2] + steps[i], cache[i - 3] + steps[i - 1] + steps[i]
            )
        return cache
    else:
        return sum(steps)


print(solution(steps))
