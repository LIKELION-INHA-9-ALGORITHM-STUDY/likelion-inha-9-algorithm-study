def solution(progresses, speeds):
    answer = []
    
    completed = 0 # 하루 배포되는 작업의 수
    p = s = 0 # 포인터(or 인덱스) => 작업을 순서대로 탐색
    days = 0 # 누적 작업 기간
    
    while p <len(progresses):
        # 현재 진도와 속도 정의
        cur_progress,cur_speed = progresses[p],speeds[s]
        # 현재 진도에 누적 작업 기간 동안의 작업 반영
        cur_progress += cur_speed * days
        
        # 현재 진도가 아직 100%가 아니라면
        if cur_progress < 100:
            # 하루에 배포할 수 있는 작업량은 끝나기 때문에 answer에 반영
            if completed != 0:
                answer.append(completed)
            # 진도가 끝날 때까지 진도와 작업 기간 업데이트
            while cur_progress <100:
                cur_progress += cur_speed
                days += 1
            # 작업 하나 끝냄
            completed = 1
        
        # 현재 진도가 이미 끝났다면 하루에 배포할 수 있는 작업 +1
        else:
            completed += 1
        
        # 다음 작업으로 이동
        p += 1
        s += 1

    # 루프가 끝나고 남은 작업 추가
    answer.append(completed)
    return answer