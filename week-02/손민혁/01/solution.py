import collections
def solution(nums):
    # 폰켓몬 종류 갯수 세기
    pkms = len(collections.Counter(nums))
    
    # 최대 N/2마리 가져갈 수 있음
    max_pkms = len(nums)//2
    
    return pkms if pkms <= max_pkms else max_pkms