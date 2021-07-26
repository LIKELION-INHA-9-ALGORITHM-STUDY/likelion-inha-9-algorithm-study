import math
def solution(progresses, speeds):
    answer=[]
    days =[] #각 기능이 개발되는데 걸리는 시간 담을 리스트
    count = 0 #같이 배포되는 기능 카운트 ... ...
    for i in range(len(progresses)):
        day = math.ceil((100-progresses[i])/speeds[i]) #i번째 기능이 개발되는데 걸리는 시간
        days.append(day)
        if days[0] >= days[-1]: #i번째 기능의 개발시간이 days의 첫 번째 기능개발시간보다 작을 경우 count 1증가 
            count +=1
        else: # i번째 기능이 첫 번째 기능보다 개발시간이 클 경우
            answer.append(count) # i번째 기능전에 같이 배포되는 애들 count한 거 answer에 추가 . . . 
            count =1 # 카운트 초기화 . . . +
            days.clear() # days 초기화하고
            days.append(day) # i번째 기능의 개발 시간을 days처음으로 넣어준다 ...
        if i == len(progresses)-1: # i번째 기능이 제일 마지막 기능일경우 바로 count append
            answer.append(count)
    return answer