# 정렬을 하자

# n, m / 각 리스트
n = int(input())
n_array = list(map(int, input().split()))
n_array.sort() # 정렬
print(n_array)

m = int(input())
m_array = list(map(int, input().split()))
print(m_array)

# 이진 탐색 함수 
def binary(array, target, start, end) : 
    while start <= end : 
        mid = (start + end) //2 
        if array[mid] == target : 
            return mid 
        elif array[mid] < target : 
            return binary(array, target, mid+1, end) 
        elif array[mid] > target : 
            return binary(array, target, start, end-1) 
    return None # 찾는 값 없으면 없음으로

# 문제 
for i in m_array : 
    result = binary(n_array, i, 0, n-1)
    if result == None : 
        print('0')
    else : 
        print('1')


