k, n = map(int, input().split(" "))
cables = list()

for _ in range(k):
    cables.append(int(input()))


def binary_search(cables, target, low, high):
    middle = (low + high) // 2 # 자를 길이

    n = 0
    for cable in cables:
        n += cable // middle

    # print(low, middle, high, target)

    if low > high:
        return middle
    
    if n < target: # 최종 랜선 개수가 목적보다 적을 때. 즉, 자른 케이블 단위가 클 때
        return binary_search(cables, target, low, middle - 1)
    else:
        if ((middle - 1 + high) // 2) == middle: return middle
        return binary_search(cables, target, middle - 1, high)

total_length = sum(cables)
print(binary_search(cables, n, 0, total_length))