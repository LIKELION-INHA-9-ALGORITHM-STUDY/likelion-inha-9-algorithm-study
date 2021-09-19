n, k = map(int, input().split(" "))
bottles = list()

for _ in range(n):
    bottles.append(int(input()))

def binary_search(bottles, target_k, low, high):
    amount_per_person = (high + low) // 2
    
    k = 0
    for bottle in bottles:
        k += bottle // amount_per_person

    if low > high:
        return high

    if k > target_k:
        return binary_search(bottles, target_k, low, amount_per_person - 1)
    else:
        return binary_search(bottles, target_k, amount_per_person + 1, high)

print(binary_search(bottles, k, 0, sum(bottles)))