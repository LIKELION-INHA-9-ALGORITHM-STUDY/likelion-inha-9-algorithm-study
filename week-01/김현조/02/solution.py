## 문제 2. 전화번호 목록

# 전화번호부에 적힌 전화번호 배열 phone_book
# 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false


def solution(phone_book):
    answer = True
    # 앞부터 check하기 편하게 정렬
    phone_book.sort()

    dict = {} # 빈 dictionary data

    for x in phone_book :
        dict[x] = True # dict에 True 각각 넣음

    # 같은 문자열 check
    for x in phone_book :
        for i in range(0, len(x)-1) :
            if x[:i+1] in dict.keys() :
                answer = False # 접두어 있으면 False

    return answer