def solution(n):

    """
    3진법 방식을 조금 변형시켜 풀었습니다.
    나머지가 0,1,2 일 때, 각각 4,1,2를 answer에 추가
    단, 나머지가 0일 때, carry를 발생시켜서 다음 연산에 영향(다음 나머지 -= 1)
    """

    answer = ""

    carry = 0
    while n >= 3:
        n, r = n // 3, n % 3 + carry  # 몫, 나머지 + carry

        if r <= 0:
            carry = -1  # carry 발생
            if r == -1:
                answer = "2" + answer
            elif r == 0:
                answer = "4" + answer
        else:
            carry = 0
            if r == 1:
                answer = "1" + answer
            elif r == 2:
                answer = "2" + answer

    if n + carry == 1:
        answer = "1" + answer
    if n + carry == 2:
        answer = "2" + answer

    return answer


for n in range(1, 100):
    print(solution(n))
