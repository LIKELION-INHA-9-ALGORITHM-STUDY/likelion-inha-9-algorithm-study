def solution(lines, a, b, target):
    """풀이: 이진 탐색을 통해 최대 랜선 길이 찾기"""
    answer = 0
    while a <= b:
        m = (a + b) // 2
        cnt = 0  # 자른 랜선의 수
        for line in lines:
            cnt += line // m
            if cnt > target:
                break

        if cnt >= target:  # 자른 랜선의 수가 목표 갯수보다 넘으면 저장하고 m을 조금씩 늘리며 최대 길이 찾기
            answer = m
            a = m + 1
        else:
            b = m - 1

    return answer


k, target = list(map(int, input().split()))
lines = [int(input()) for _ in range(k)]
print(solution(lines, 1, max(lines), target))
