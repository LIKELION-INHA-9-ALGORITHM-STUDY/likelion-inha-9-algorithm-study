from collections import Counter # 데이터 개수를 세는 클래스
import sys

n = int(sys.stdin.readline())
data = []

for i in range (1, n + 1):
    a = int(sys.stdin.readline())
    data.append(a)

# 산술평균
ave = round(sum(data) / n)

# 중앙값
data.sort()
mid = data[n // 2]

# 최빈값
if(len(data) == 1):
    mod = data[0]
else:
    counter = Counter(data).most_common()
    # data : [2, 4, 4, 6, 6, 6] 일 때
    # count -> [(2,1), (4,2), (6,3)]
    if counter[0][1] == counter[1][1]:
        mod = counter[1][0] # 최빈값이 두 개 이상일 때 두 번째로 작은 값 출력
    else:
        mod = counter[0][0]

# 범위
if(len(data) == 1):
    ran = 0
else:
    ran = data[n-1] - data[0]

print(f"{ave}\n{mid}\n{mod}\n{ran}")