import sys

n = int(sys.stdin.readline())

expected = []
for _ in range(n):
    expected.append(int(sys.stdin.readline()))
expected.sort()

"""학생들의 기대 점수를 오름차순으로 정렬 후 순서대로 1등부터 매기면서 불만도를 계산하기"""

answers = 0
for i, v in enumerate(expected):
    answers += abs(i + 1 - v)
print(answers)
