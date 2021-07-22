def solution(clothes):
    hash_map = {}
    
    for c in clothes:
        cloth_category = c[1]
        
        if hash_map.get(cloth_category) == None:
            hash_map[cloth_category] = 1
        else:
            hash_map[cloth_category] += 1
            
    result = 1
    for v in hash_map.values():
        result *= (v + 1)
    
    return result - 1

# 고등학교때 배운 순열과 조합이 많이 생각나는 풀이입니다.
# 문제에 대해 인터넷에 조금 검색했습니다 ㅎㅎ...
# 옷의 종류별 가짓수에 1을 더해 모두 곱한 뒤 1을 빼줍니다.
# 가짓수에 1을 더하는 이유는 그 종류의 옷을 입지 않은 상황까지 계산하기 위해서입니다.
# 마지막에서 1을 뺴주는 이유는 모든 종류의 옷을 입지 않은 1가지 경우를 제외하기 위해서입니다.