from collections import defaultdict

n = int(input())
n_list = list(map(int, input().split(" ")))

m = int(input())
m_list = list(map(int, input().split(" ")))

hash = defaultdict(lambda : 0)

for card in n_list:
    hash[card] += 1

for check in m_list:
    print(hash[check], end=" ")