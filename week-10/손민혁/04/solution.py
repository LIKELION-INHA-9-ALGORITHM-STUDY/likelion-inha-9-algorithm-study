n = int(input())


def solution(n):
    n_sqrt = int(n ** 0.5)  # n과 가장 가까운 제곱수
    min_cost = 4  # 기본으로 가능한 최소 계산 횟수는 4(제일 크게) 설정
    for i in range(n_sqrt, 0, -1):
        target = n
        if target - i * i == 0:
            return 1  # 타겟값 n이 제곱수이면 바로 1 리턴

        for j in range(i, 0, -1):
            target = n - i * i
            if target - j * j < 0:
                continue  # 타겟값이 음수가 되는 경우는 넘어감
            if target - j * j == 0:
                return 2  # 타겟값이 제곱수인 경우를 제외하고 가능한 최소 계산 횟수는 2이기 때문에 찾으면 바로 리턴

            for k in range(j, 0, -1):
                target = n - i * i - j * j
                if target - k * k < 0:
                    continue
                if target - k * k == 0:
                    min_cost = 3
                    # 여기서 바로 리턴을 해주면 위의 2개의 제곱수로 계산하는 경우를 찾지 못하기 때문에 바로 리턴하지 않음
    return min_cost


print(solution(n))
