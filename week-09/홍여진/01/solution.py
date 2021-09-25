import sys
numbers = []  # 입력받은 수열
stack = []  # 스택 !!!
answer = []  # +, - 넣을 곳
n = int(input())
def read(): return sys.stdin.readline()


for i in range(n):
    t = int(read())
    numbers.append(t)
num = 0
r = 0
cnt = 0
for i in range(n):
    # 반환해야할 숫자가 스택에 들어올때까지 push
    while (len(stack) == 0 or stack[-1] < numbers[i]):
        num += 1
        stack.append(num)
        answer.append('+')

    if (stack[-1] == numbers[i]):  # 반환해야할 숫자가 top에 있으면 pop
        stack.pop()
        answer.append('-')
        cnt += 1
if cnt == n:  # 모든 수가 반환됐는지 확인
    for a in answer:
        print(a)
else:
    print('NO')
