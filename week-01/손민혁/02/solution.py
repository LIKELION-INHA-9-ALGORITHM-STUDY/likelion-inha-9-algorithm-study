def solution(phone_book):

    """핵심은 타임아웃을 피하는 것"""
    
    answer = True
    phone_book.sort()  # 숫자를 오름차순으로 정렬해줍니다. Why? - 최대한 숫자(의 접두사)가 비슷한 녀석들끼리 정렬시키기 위해
    for i in range(len(phone_book) - 1):
        # 첫 번째 요소부터 뒤에 있는 요소들과 비교합니다.
        num1 = phone_book[i]
        for j in range(i + 1, len(phone_book)):
            num2 = phone_book[j]
            # 1. 접두사의 조건
            if num1[0] == num2[0] and num1 in num2:
                return False
            # 2. 최대한 빠른 탐색을 위해 '1. 접두사의 조건'을 만족시키지 못하면 루프를 끝내고 다음 루프 탐색
            else:
                break

    return answer
