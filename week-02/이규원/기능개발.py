from math import * 

def solution(progresses, speeds):  

    d=[] #남은 작업 일수를 담는 리스트
    answer=[] 
    cnt=1  

    for i in range(0,len(progresses)):
        d.append(ceil((100-progresses[i])/speeds[i])) 
        if i==0: 
            std=d[0]
        else:
            if std>=d[i]: 
                cnt+=1
                if i==len(progresses)-1: #인덱스가 마지막인 경우, 조건에 관계없이 배포 일수 추가
                    answer.append(cnt)
            elif std<d[i]: 
                std=d[i]        #현재 값이 새로운 기준값이 된다
                answer.append(cnt) 
                cnt=1 
                if i==len(progresses)-1:
                    answer.append(cnt)
    return answer