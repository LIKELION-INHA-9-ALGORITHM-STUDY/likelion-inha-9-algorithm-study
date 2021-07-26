def solution(clothes):

    cnt=1 #카테고리별 옷의 개수를 셀 때 쓰는 변수(카테고리마다 적어도 한 가지는 있으므로 1로 초기화)
    flag=0 #조건을 나타내기 위한 변수
    num_same_gear=[] #각 카테고리에 몇 벌의 옷이 있는지 저장하는 리스트
    gear=[] #카테고리의 종류
    answer=1 #반복문에서 곱셈을 하므로 초기값은 1로 설정(

    #의상의 종류만으로 이루어진 gear list 생성
    for i in range(0,len(clothes)):
            gear.append(clothes[i][1])

    #의상의 종류는 알파벳 순으로 sort하여 "같은 요소"끼리 배열 (예:gear=["a","a","b","b","b","c"])
    gear=sorted(gear,key=str.lower)
    print(gear)


    for i in range(0,len(clothes)):
        for j in range(i+1,len(clothes)):
            if (i!=0)&(gear[i]==gear[i-1]): #두번째 인덱스부터(idx=1) 이전 요소와 현재 요소가 같은 경우, 이전 요소 때 이미 개수를 셌으므로 스킵
                flag=1
                break
            elif (gear[i]==gear[j]): #첫번째 인덱스(idx=0)인 경우 나머지 요소들과 비교 & 이전 요소와 현재 요소가 달라진 경우(예:"a"->"b")
                cnt=cnt+1 #요소의 개수를 센다
            else: 
                continue
        if i+1==len(clothes):
            break
        elif (flag==0):        
            num_same_gear.append(cnt) #조건에 맞는 경우, cnt 값(각 카테고리 별 옷의 개수)를 num_same_gear 리스트에 추가한다
            cnt=1 #카테고리별 옷의 개수 1로 초기화
        else:
            flag=0
            continue

    #리스트에는 각 카테고리 별 옷의 개수가 저장되어 있다.
    #각 카테고리에서 스파이는 옷을 안 입거나 종류 중에 하나를 입거나의 경우가 있으므로 "각 카테고리 별 옷의 개수+1"가지의 경우가 카테고리마다 있고,
    #적어도 하나를 입으므로 "아무것도 안 입는 경우(1가지)"를 제외하면
    #아래와 같다
    for i in range(0,len(num_same_gear)): 
        answer=answer*(num_same_gear[i]+1)
    answer=answer-1

    return answer