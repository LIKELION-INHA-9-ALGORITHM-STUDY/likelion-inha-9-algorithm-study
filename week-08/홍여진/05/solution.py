def solution(n, times):
    low = 0
    high = max(times)*n
    while low < high:
        middle = (low+high)//2
        sum = 0
        for t in times:
            sum += middle//t  # 주어진 시간이 middle일 때 심사할 수 있는 최대 인원의 수
        if sum >= n:
            high = middle
        elif sum < n:
            low = middle+1

    answer = low  # n명을 심사할 수 있는 최소 시간을 리턴
    return answer


n = 1
times = [100, 99, 99]

print(solution(n, times))
