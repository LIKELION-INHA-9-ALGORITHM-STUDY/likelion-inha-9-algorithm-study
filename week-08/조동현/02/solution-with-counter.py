from collections import Counter

n = int(input())
n_list = sorted(map(int, input().split(" ")))

m = int(input())
m_list = list(map(int, input().split(" ")))

c = Counter(n_list)
for check in m_list: print(c[check], end=" ")

# 이건 솔직히 반칙이다