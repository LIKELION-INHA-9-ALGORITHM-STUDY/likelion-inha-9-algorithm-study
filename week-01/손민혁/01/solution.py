import collections

""" 파이썬 내장 함수 collections를 불러와 해결해 보았습니다. 
저도 collections가 아직 익숙치 않은데 알아두면 유용할거 같아요 !! """

def solution(participant, completion):
    p = collections.Counter(participant)
    # p:  Counter({'mislav': 2, 'stanko': 1, 'ana': 1})
    c = collections.Counter(completion)
    # c:  Counter({'stanko': 1, 'ana': 1, 'mislav': 1})
    ans = p - c
    # ans:  Counter({'mislav': 1})
    return ans.most_common(1)[0][0]
