from collections import deque

def calc_max_trucks(target, max, deq):
	count = 0
	for d in deq:
		target += d
		if target > max:
			break
		count += 1
	return count



def solution(bridge_length, weight, truck_weights):
	total_time = 0
	trucks = deque(truck_weights)
	while(trucks):
		truck_num = calc_max_trucks(trucks.popleft(), weight, trucks)
		total_time += bridge_length - truck_num
	return total_time + 1