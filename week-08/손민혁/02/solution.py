from collections import Counter


def solution(counter, target):
    """풀이: 이진 탐색 시도하다 잘 안되서 카운터 불렀습니다.. 역시 든든하네요 ㅎㅎ"""
    ans = 0
    try:
        c = counter[target]
        ans = c
    except:
        ans = 0
    return ans


n = int(input())
cards = list(map(int, input().split()))
m = int(input())
sg = list(map(int, input().split()))
counter = Counter(cards)

for target in sg:
    print(solution(counter, target), end=" ")
