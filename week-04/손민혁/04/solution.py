def solution(K):
    """어떤 자연수가 3개의 삼각수의 합인 조건
    1) 어떤 삼각수의 3개의 합
    2) 어떤 삼각수의 2개의 합 + 다른 삼각수 하나의 합
    3) 서로 다른 3개의 삼각수의 합"""

    def triangle_number(n):
        """삼각수 만드는 함수"""
        return int(n * (n + 1) / 2)

    # 삼각수 만들기
    tnums = [triangle_number(n) for n in range(1, 50) if triangle_number(n) < K]

    for t in tnums:
        # t1: 1번의 조건, t2: 2번의 조건
        t1 = 3 * t
        t2 = K - 2 * t
        if t1 == K or t2 in tnums:
            return 1
        if t1 > K and t2 < 0:
            break

    for i in range(len(tnums)):
        for j in range(i + 1, len(tnums)):
            for k in range(j + 1, len(tnums)):
                # 3번의 조건
                target = tnums[i] + tnums[j] + tnums[k]
                if target == K:
                    return 1
                if target > K:
                    break
    return 0


n = int(input())
for _ in range(len(n)):
    K = int(input())
    print(solution(K))
