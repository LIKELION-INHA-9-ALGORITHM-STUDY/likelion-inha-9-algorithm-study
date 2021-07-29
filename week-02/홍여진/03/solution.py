#내가 ... 뭘만들고있는거지?
from collections import deque
def solution(bridge_length, weight, truck_weights):
    truck_weights.reverse()
    answers = deque([]) # 각 차들의... 다리 건너편 도착시간모음...
    passing = deque([]) # 다리를 건너고 있는 차들...
    time = 1 
    sum_passing = 0 #다리 위를 지나가고 있는 차들의 무게 총합
    while True:
        try:
            if answers[0] == time: #맨 앞의 차가 다리 건너편에 도착했을때
                answers.popleft()
                sum_passing -= passing[0] 
                passing.popleft()
        except IndexError: # 초기 answers랑 passing이 []일 때
            pass

        if (weight >= sum_passing+truck_weights[-1]): # 현재 다리를 건너고있는 차들의 무게+다음에 올 차의 무게가 weight이하일 경우
            passing.append(truck_weights[-1])
            sum_passing += truck_weights[-1]
            truck_weights.pop()
            answers.append(bridge_length+time)
        if len(truck_weights) == 0:
            return answers[-1]# 가장 마지막에 건너는 차의 도착시간 == 모든 차들이 다리를 건넌 최소시간
        time += 1