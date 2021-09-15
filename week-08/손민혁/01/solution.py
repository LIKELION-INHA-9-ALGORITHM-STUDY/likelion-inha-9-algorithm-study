import bisect  # 이진 탐색 라이브러리


def solution(l, target):
    """풀이: 이진 탐색으로 리스트(l)에서 target과 일치하거나 가까운 인덱스를 찾고 해당 인덱스의 값과 target값을 비교해 일치하면 True"""
    i = bisect.bisect_left(l, target)
    return i < len(l) and l[i] == target


n = int(input())
l = list(map(int, input().split()))
m = int(input())
targets = list(map(int, input().split()))
l.sort()  # 오름차순 정렬
for t in targets:
    print(int(solution(l, t)))
