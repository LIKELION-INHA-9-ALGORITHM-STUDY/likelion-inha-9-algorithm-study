def solution(phone_book):
    hash_map = {}
    
    # 전화번호로 해시 테이블을 만듭니다
    for p in phone_book:
        hash_map[p] = True
    
    # 각 전화번호를 첫글자부터 끝글자까지 잘라보며 해시테이블에 존재하는지 유무를 확인합니다
    for p in phone_book:
        for l in range(1, len(p)):
            sliced_letter = p[0:l]
            if hash_map.get(sliced_letter): return False
    
    return True