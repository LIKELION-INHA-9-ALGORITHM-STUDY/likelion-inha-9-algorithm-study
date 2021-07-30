from collections import deque

# 다리 길이만큼 0넣어준 데크 반환
def create_bridge(bridge_length):
	bridge = deque()
	for _ in range(bridge_length):
		bridge.append(0)
	return bridge

def solution(bridge_length, weight, truck_weights):
	bridge_weight = 0 #다리 무게
	total_time = 0 #총 시간
	truck_num = len(truck_weights) #트럭 개수
	bridge = create_bridge(bridge_length) # 브릿지
	idx = 0 # truck_weights리스트를 조회할 index
	
	while(idx < truck_num):
		total_time += 1
		bridge_weight -= bridge.popleft()
		truck_weight = truck_weights[idx]
		if truck_weight + bridge_weight <= weight :
			bridge.append(truck_weight)
			bridge_weight += truck_weight
			idx += 1
		else:
			bridge.append(0)
	total_time += bridge_length
	return total_time