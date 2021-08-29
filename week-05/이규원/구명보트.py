def solution(people, limit):
    people.sort(reverse=True) #몸무게가 많이 나가는 순으로 정렬
    answer=0
    idx_front=0 #인덱스 앞에서부터 
    idx_end=len(people)-1 #인덱스 뒤에서부터 
    while(idx_front<idx_end): #앞에서부터 진행하던 인덱스값이 뒤에서부터 진행해오는 인덱스와 만나기 전까지 
        weight=people[idx_front]+people[idx_end] #
        if(weight>limit): #두 사람의 무게가 제한 무게를 초과하는 경우
            idx_front+=1 #그 다음으로 무거운 사람으로 인덱스 이동
            answer+=1 #무거운 사람이 보트에 탑승
            continue
        else: #두 사람의 무게가 제한 무게를 초과하지 않는 경우 
            idx_front+=1 #보트 탑승후, 앞, 뒤 인덱스 모두 이동
            idx_end-=1
        answer+=1 #제한 무게 초과하지 않은 경우 '두 사람이 함께 탈 하나의 보트' 추가
    if idx_front==idx_end: #가운데 남는 사람이 있는 경우(전체 인원이 홀수인 경우)
        answer+=1 #남는 한 사람을 위한 보트 추가
    return answer