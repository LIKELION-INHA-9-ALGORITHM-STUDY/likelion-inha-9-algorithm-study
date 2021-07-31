class BridgeQueue:
    def __init__(self, length, weight):
        self.weight = weight
        self.bridge = [None] * length

    # 다리위에 올라와있는 차량의 모든 무게
    def total_truck_weight(self):
        total_truck_weight = 0
        for w in self.bridge:
            if w != None:
                total_truck_weight += w
        return total_truck_weight

    # 파라미터로 넣어준 트럭을 다리위에 올릴 수 있는지 체크
    def check_weight(self, truck_weight):
        if truck_weight == None: truck_weight = 0

        return self.total_truck_weight() + truck_weight <= self.weight

    def dequeue(self):
        self.bridge.append(None)
        return self.bridge.pop(0)

    def enqueue(self, truck_weight):
        self.bridge[-1] = truck_weight

    # 파라미터로 받아온 차량을 다리위에 올리고 동시에 내릴 차량을 내리는 작업
    # 튜플 (차량 올리기 성공여부, 소요시간) 을 반환
    def step(self, truck_weight):
        self.dequeue()

        if self.check_weight(truck_weight):
            self.enqueue(truck_weight)
        else:
            # 다리 무게 한도에 도달하였을 때는
            # 가장 앞에 달리고 있는 차량의 앞칸을 생략하고, 생략한 만큼 소요시간을 반환
            skip_count = 0
            for i, w in enumerate(self.bridge):
                skip_count = i
                if w != None: break

            # 생략한 만큼 차량을 앞으로 이동시키고
            # 차량 뒤에 생략한 만큼 빈공간을 채워넣음
            new_bridge = self.bridge[skip_count:] + [None] * skip_count

            self.bridge = new_bridge
            return (False, skip_count + 1)

        return (True, 1)

def solution(bridge_length, weight, waiting_trucks):
    bridge = BridgeQueue(bridge_length, weight)

    trucks_count = len(waiting_trucks)

    seconds = 0
    while True:
        # 대기 차량이 0이고, 다리위 차량도 없으면 반복 탈출
        if len(waiting_trucks) <= 0 and bridge.total_truck_weight() == 0:
            break

        # 더이상 다리위에 올릴 트럭이 없으면 None 을 계속 올림
        # 이미 올라가있는 트럭을 계속 밀어주기 위함
        in_truck = None
        if len(waiting_trucks) > 0:
            in_truck = waiting_trucks[0]

        # in_success : 트럭이 다리위에 성공적으로 올라갔는가?
        # s : 이번 스텝에서 소요된 시간 (초)
        in_success, s = bridge.step(in_truck)

        # 트럭이 다리위에 올라간 경우만 트럭 대기열에서 제거
        if in_success and (len(waiting_trucks) > 0):
            waiting_trucks.pop(0)

        seconds += s

    return seconds