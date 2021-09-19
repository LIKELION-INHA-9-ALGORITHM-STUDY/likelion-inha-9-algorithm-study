def solution(drinks, friends):
    """풀이: 이진 탐색으로 friends에게 나눠 줄 수 있는 최대 용량을 찾는다."""
    a, b = 1, max(drinks)
    answer = 0
    while a <= b:
        shots = 0  # 막걸리 잔 수
        m = (a + b) // 2  # 한 잔 당 배분하는 용량(최소와 최댓값의 중앙값 m)
        for drink in drinks:
            shots += drink // m

        if shots < friends:  # 친구의 수 만큼 잔이 안나오면 m값을 줄여야 한다.
            b = m - 1
        else:  # 친구의 수 만큼 잔이 나오면 m값을 키워 최댓값을 찾는다.
            answer = m
            a = m + 1
    return answer


n, k = list(map(int, input().split()))
drinks = [int(input()) for _ in range(n)]
print(solution(drinks, k))
