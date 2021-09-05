data = [0 for _ in range(12)]
data[1] = 1
data[2] = 2
data[3] = 4
count = int(input())


def solution(num):
    if num == 0:
        return 0
    if data[num] != 0:
        return data[num]
    data[num] = solution(num-1) + solution(num-2) + solution(num-3)
    return data[num]


for _ in range(count):
    num = int(input())
    print(solution(num))
