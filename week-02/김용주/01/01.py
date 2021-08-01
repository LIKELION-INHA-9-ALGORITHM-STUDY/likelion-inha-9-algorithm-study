import collections
def solution(nums):
    answer = 0
    check = collections.Counter(nums)
    if len(nums)/2 < len(check):
        answer = len(nums)/2
    else:
        answer = len(check)
    return answer
# 지난주의 Counter 함수가 너무 신기해서 써봤는데 
# set이라는 더 좋은 함수가 있더라고요 하하