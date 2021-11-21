import sys
from collections import deque

n = int(sys.stdin.readline())
if n == 1:  # 예외 처리
    print(1)
else:
    cards = deque([2 * i for i in range(1, n // 2 + 1)])  # 짝수들만 리스트로 만듬

    # 홀수번째 카드는 제거, 짝수번째 카드는 맨 뒤로 보냄
    # n이 짝수면 제거부터 시작, 홀수면 맨 뒤로 보내기부터 시작
    cnt = 0
    if n % 2 == 0:
        cnt += 1
    while len(cards) > 1:
        num = cards.popleft()  # 카드 뽑기
        if cnt % 2 == 0:  # 짝수번쨰 카드는 맨 뒤로, 홀수번째는 제거
            cards.append(num)
        cnt += 1

    print(cards[-1])
