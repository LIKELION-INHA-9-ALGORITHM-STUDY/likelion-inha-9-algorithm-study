from itertools import permutations


def solution(numbers):
    def isPrime(num):
        """소수 판별 함수: 1과 자신 이외의 수로 나누어 떨어지면 False"""
        if num <= 1:
            return False

        for i in range(2, num):
            if num % i == 0:
                return False

        return True

    answer = 0
    numbers = [n for n in numbers]  # str => list // ["1","7"]
    checked = []  # 중복 검사용 리스트
    for i in range(1, len(numbers) + 1):
        pers = permutations(
            numbers, i
        )  # pers: numbers에서 i개를 뽑은 순열들을 담은 객체 // [("1","7"), ("7","1")]
        for per in pers:  # per: ("1","7"), ("7","1")
            s = ""
            for num in per:  # num: "1" or "7"..
                s += num
            number = int(s)  # number: 17 or 71 ...
            if number not in checked and isPrime(number):  # 중복 검사 및 소수 판별
                checked.append(number)
                answer += 1
    return answer
