from itertools import combinations

def solution(clothes):
    hash_map = {}
    
    for c in clothes:
        cloth_category = c[1]
        
        if hash_map.get(cloth_category) == None:
            hash_map[cloth_category] = 1
        else:
            hash_map[cloth_category] += 1
    
    category_list = hash_map.keys()
    category_count = len(category_list)
    
    category_combination = []
    for r in range(1, category_count + 1):
        category_combination.extend(
            combinations(category_list, r)
        )
    
    result = 0
    for i in category_combination:
        multiply = 1
        for j in i:
            multiply *= hash_map[j]
        result += multiply
    
    return result

# 위와 같이 풀었으나 1번 테스트케이스에서 시간초과 오류가 계속 발생했습니다.
# 극단적인 테스트 케이스로 옷의 종류가 30개인 경우를 넣어주니, 시간초과가 발생했습니다.
# 이후 프로그래머스 질답을 확인해보니 1번 테스트 케이스가 옷의 종류 30개가 맞다고 합니다.