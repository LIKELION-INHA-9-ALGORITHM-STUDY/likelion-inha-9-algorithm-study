def solution(participant, completion):

    cnt=0 #participant와 completion에서 같은 이름의 선수가 있는지 판별하기 위한 변수
    same_name=[] #participant 내에서 동명이인 찾기 위한 변수
    same_name_comp=[] #completion 내에서 동명이인 찾기 위한 변수

    #participant에서 동명이인을 찾는다
    for i in range(0,len(participant)):
        for j in range(0,len(participant)):
            if (i!=j)&(participant[i]==participant[j]):
                same_name.append(participant[i]) 

    #completion에서 동명이인을 찾는다  
    for i in range(0,len(completion)):
        for j in range(0,len(completion)):
            if (i!=j)&(completion[i]==completion[j]):
                same_name_comp.append(completion[i]) 
    
    #participant의 동명이인 수가 completion의 동명이인 수보다 많으면 그 선수가 완주하지 못한 선수가 되므로 뒤의 과정은 생략할 수 있다
    if (len(same_name)!=0)&(len(same_name)!=len(same_name_comp)):
        answer=same_name[0]
    
    #동명이인 수가 같은 경우 이름을 두 집단에서 비교하여 같은 이름이 있는 경우 cnt를 1로 만들고, 없는 경우 cnt가 1이 아님을 이용하여 판별한다
    for i in range(0,len(participant)):
        for j in range(0,len(completion)):
            if participant[i]==completion[j]:
                cnt=cnt+1
        if cnt==1:
            cnt=0
            continue
        else:
            answer=participant[i]          
    return answer