## 문제 3. 위장

# 매일 다른 옷 조합 - 얼굴 상의 하의 겉옷
# 의상 2차원 배열 clothes -> 조합수 return

def solution(clothes):
    answer = 1

    dict = {} # 빈 dictionary data

    for x in clothes : # 종류 check
        if x[1] in dict :
            dict[x[1]] += 1
        else :
            dict[x[1]] = 1

    for x in dict :
        answer *=(dict[x]+1)

    answer -= 1
    
    return answer