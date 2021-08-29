def solution(n, lost, reserve):
    new_lost = set(lost) - set(reserve)
    new_reserve = set(reserve) - set(lost)
    # 여벌을 가져오고 도난당했으면, 도난자, 여벌보유자 리스트에서 제외
    
    for s in new_reserve:
        if (s - 1 in new_lost): new_lost.remove(s - 1)
        elif (s + 1 in new_lost): new_lost.remove(s + 1)
            
    return n - len(new_lost)