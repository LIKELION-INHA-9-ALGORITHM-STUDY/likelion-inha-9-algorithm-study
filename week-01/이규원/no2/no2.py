def solution(phone_book):   
    answer=True #default는 True로 설정한다
    phone_book=sorted(phone_book,key=len) #번호의 길이를 기준으로 짧은 것부터 정렬한다
    for k in range(0,len(phone_book)): 
        compare_val=phone_book[k] 
        for i in range(k+1,len(phone_book)): #두번째 반복문은 비교하고자 하는 요소의 "다음 인덱스부터 끝까지"
            tobeCompared=phone_book[i] 
            if compare_val==tobeCompared[0:len(compare_val)]: #비교하고자 하는 값==비교하는 값의 접두사
                answer=False #한 번호가 다른 번호의 접두사가 되므로 False로 변경
                break
            else: 
                continue 
        if answer==False: #False인 경우 반복문 탈출하고 함수 종료
            break
        else: 
            continue

    return answer