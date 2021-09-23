from collections import deque

n = int(input())
answer = deque()
for _ in range(n):
    answer.append(int(input()))

""" 
문제: 스택 연산은 numbers -("push")-> stack -("pop")-> answer와 비교로 이루어진다.

풀이: answer에서 순서대로 탐색하며 위의 스택 연산이 가능한지 판단한다. 가능하면 "+" 혹은 "-" 연산을 저장, 그렇지 않으면 "NO" 리턴
"""


def solution(answer, n):
    stack = [0]
    numbers = deque(range(1, n + 1))
    oper = []

    while answer:
        a = answer.popleft()
        if stack[-1] < a:
            while True:
                n = numbers.popleft()
                if n == a:
                    oper += ["+", "-"]
                    break
                stack.append(n)
                oper += ["+"]
        elif stack[-1] == a:
            stack.pop()
            oper += ["-"]

        else:
            print("NO")
            return

    for o in oper:
        print(o)


solution(answer, n)
