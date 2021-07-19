from itertools import combinations
from collections import defaultdict

def solution(clothes):
    
    """ 테스트 1 타임아웃"""
    
    def get_multiple(tuple):
        
        """ tuple 요소들의 곱을 리턴 """
        
        r = 1
        for n in tuple:
            r *= n
        return r
    
    # 옷 종류별 개수 세기
    dic = defaultdict(int)
    for c in clothes:
        dic[c[1]] += 1
    clothes_list = dic.values()
    
    if len(clothes) == len(clothes_list):
        print(dic)
        res = 0
        for i in range(1,len(clothes)+1):
            for _ in combinations(clothes_list,i):
                print(_)
                res +=1
        return res
    
    answer = sum(clothes_list)
    for i in range(2,len(clothes_list)+1):
        
        for tuple in combinations(clothes_list, i):
            answer += get_multiple(tuple)
    return answer