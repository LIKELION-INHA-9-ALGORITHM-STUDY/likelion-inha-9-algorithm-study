# (bridge_length, weight, truck_weights[]) => {
#	truck_weights[]배열안의 트럭들이
#	weight만큼의 무게를 견딜 수 있는 다리길이 bridge_length 건너는 시간 total_time을 구해서
#	return (total_time)
# }
from queue import Queue

def solution(bridge_length, weight, truck_weights):
	bridge = Queue() #다리 queue
	bridge_weight = 0 #다리 무게
	total_time = 0 #총 시간
	j = 0
	truck_num = len(truck_weights) #트럭 개수
	
	#queue에 다리 길이만큼 0넣어주기
	for _ in range(bridge_length):
		bridge.put(0)
	while(j < truck_num):
		truck_weight = truck_weights[j]
		bridge_weight -= bridge.get()
		if truck_weight + bridge_weight <= weight :
			bridge.put(truck_weight)
			bridge_weight += truck_weight
			j += 1
		else:
			bridge.put(0)
		total_time += 1
	total_time += bridge_length
	return total_time


solution(2, 10, [7, 4, 5, 6])