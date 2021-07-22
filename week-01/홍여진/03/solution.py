def solution(clothes):
    answer = 1
    d={}
    for i in clothes:
        if i[1] in d: #d의 키에 i[1]이 있다면
            d[i[1]] = d[i[1]]+1 #해당 value에 1 더함.
        else:
            d[i[1]] = 1 #없다면 새로 만든다. d에 추가
    for i in d:
        d[i] = d[i]+1 #해당 종류의 옷을 입지않는 경우도 있으므로 +1해줌
    for i in d:
        answer = answer * d[i] #경우의 수 구함
    return answer-1 #최소 한 개의 의상은 입으므로 -1(옷을 모두 입지않는 경우 제거)