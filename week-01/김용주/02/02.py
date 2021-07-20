def solution(phone_book):
    answer = True
    num={}
    for number in phone_book:
        num[number]=len(number)
    for number in phone_book:
        for i in range (len(number)):
            if number[0:i] in num:
                return False
    return answer