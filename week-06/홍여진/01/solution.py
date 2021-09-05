data = [0 for _ in range(91)]
num = int(input())


def fibo(num):
    if num == 0:
        return 0
    if num == 1 or num == 2:
        return 1
    if data[num] != 0:
        return data[num]
    data[num] = fibo(num-1) + fibo(num-2)
    return data[num]


print(fibo(num))
