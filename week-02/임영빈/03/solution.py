from queue import Queue

# 다리 길이만큼 0넣어준 큐 반환
def create_queue(length):
	q = Queue()
	for _ in range(length):
		q.put(0)
	return q

def solution(bridge_length, weight, truck_weights):
	bridge_weight = 0 #다리 무게
	total_time = 0 #총 시간
	truck_num = len(truck_weights) #트럭 개수
	bridge = create_queue(bridge_length)
	idx = 0
	
	while(idx < truck_num):
		total_time += 1
		bridge_weight -= bridge.get()
		truck_weight = truck_weights[idx]
		if truck_weight + bridge_weight <= weight :
			bridge.put(truck_weight)
			bridge_weight += truck_weight
			idx += 1
		else:
			bridge.put(0)
	total_time += bridge_length
	return total_time