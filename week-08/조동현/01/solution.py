n = int(input())
n_list = sorted(map(int, input().split(" ")))

m = int(input())
m_list = map(int, input().split(" "))

def binary_search(array, target, left, right):

    middle_index = (right+left) // 2
    middle_number = array[middle_index]
    
    if left > right:
        return 0

    if middle_number == target:
        return 1
    elif middle_number > target: # 좌측을 살림
        return binary_search(array, target, left, middle_index - 1)
    elif middle_number < target: # 우측을 살림
        return binary_search(array, target, middle_index + 1, right)

for target in m_list:
    print(binary_search(n_list, target, 0, len(n_list) - 1))