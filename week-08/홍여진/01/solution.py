n = int(input())
n_list = list(map(int, input().split(" ")))
n_list.sort()
m = int(input())
m_list = list(map(int, input().split(" ")))


def binary_search(data, target, low, high):
    middle = (low+high)//2
    if low > high:
        return 0
    if data[middle] == target:
        return 1
    elif data[middle] > target:
        return binary_search(data, target, low, middle-1)
    else:
        return binary_search(data, target, middle+1, high)


for i in m_list:
    print(binary_search(n_list, i, 0, len(n_list)-1))
