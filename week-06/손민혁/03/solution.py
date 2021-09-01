def fact(n):
    """팩토리얼 구하는 함수"""
    if n == 0:
        return 1
    if n == 1:
        return 1
    return n * fact(n - 1)


def cmb(n, r):
    """조합 구하는 함수 : nCr"""
    return int(fact(n) / (fact(r) * fact(n - r)))


def solution(n):
    """가능한 모든 조건을 고려해 조합을 이용해 계산했습니다!"""
    ans = 0
    # case1: 1로만 이루어짐
    ans += 1
    # case2: 2로만 이루어짐
    if n % 2 == 0:
        ans += 1
    # case3: 3으로만 이루어짐
    if n % 3 == 0:
        ans += 1
    # case4: 1과 2로 이루어짐
    i = 1
    while True:
        if (n - 2 * i) >= 1:
            ans += cmb(n - 2 * i + i, i)
            i += 1
        else:
            break
    # case5: 1과 3으로 이루어짐
    i = 1
    while True:
        if (n - 3 * i) >= 1:
            ans += cmb(n - 3 * i + i, i)
            i += 1
        else:
            break

    # case6: 2와 3으로 이루어짐
    if n >= 5:
        for i in range(1, 4):
            for j in range(1, 5):
                num = n - 3 * i - 2 * j
                if num == 0:
                    ans += cmb(i + j, i)
    # case7: 1,2,3으로 이루어짐
    if n >= 6:
        for i in range(1, 3):
            for j in range(1, 4):
                for k in range(1, 7):
                    num = n - 3 * i - 2 * j - k
                    if num == 0:
                        ans += cmb(i + j + k, i) * cmb(j + k, j)
                    else:
                        continue

    return ans
