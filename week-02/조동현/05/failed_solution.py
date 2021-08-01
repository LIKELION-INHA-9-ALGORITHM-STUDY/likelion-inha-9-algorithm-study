def factorial(x, start=1):
    ret = 1
    for v in range(start, x + 1):
        ret *= v
        
    return ret

def solution(n):
    max_one_area_cnt = n % 2
    max_two_area_cnt = (n - max_one_area_cnt) // 2
    
    areas_combinations = []
    for i in range(max_two_area_cnt + 1):
        one_count = (max_two_area_cnt - i) * 2 + max_one_area_cnt
        two_count = i
        
        areas_combinations.append(
            (one_count, two_count)
        )
    
    ret = 0
    for area in areas_combinations:
        one_count = area[0]
        two_count = area[1]
        
        smaller = one_count if one_count < two_count else two_count
        larger = one_count if one_count >= two_count else two_count
        
        ret += factorial(one_count + two_count, larger + 1) // factorial(smaller)
        
    return ret % 1000000007