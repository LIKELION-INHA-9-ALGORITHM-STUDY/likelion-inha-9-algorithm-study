# 
# n, m / 각 리스트
n = int(input())
n_array = list(map(int, input().split()))
n_array.sort() # 정렬
print(n_array)

m = int(input())
m_array = list(map(int, input().split()))
print(m_array)

i = 0 
while i <= len(m_array) : 
    print(n_array.count(m_array[i]))
    i += 1 

#  line 16, in <module>
#     print(n_array.count(m_array[i]))
# IndexError: list index out of range
