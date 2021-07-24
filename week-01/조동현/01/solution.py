def solution(participant, completion):
    hash_map = {}
    
    # 해시 테이블을 만들어 참가자 명단을 추가합니다.
    # 이때, 해시 테이블의 Value 는 참가자 등장 수 입니다.
    for p in participant:
        if p in hash_map.keys():
            hash_map[p] += 1
        else:
            hash_map[p] = 1
    
    # 완주자로 Loop 을 돌며, 해시 테이블에서 해당하는 참가자의 수를 줄 입니다.
    for c in completion:
        hash_map[c] -= 1
    
    # 해시테이블의 Value 가 1인 사람이 완주하지 못한 사람입니다.
    for k in hash_map.keys():
        if hash_map[k] == 1:
            return k