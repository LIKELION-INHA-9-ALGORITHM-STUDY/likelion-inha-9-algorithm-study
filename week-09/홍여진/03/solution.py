numbers = input().split('-')
sum = 0
for n in numbers[0].split('+'):
    sum += int(n)  # 맨 처음 수를 SUM에 넣음


for i in range(1, len(numbers)):
    for n in numbers[i].split('+'):
        sum -= int(n)  # -뒤 양수들을 괄호쳐서 한 번에 뺌

print(sum)
