from collections import Counter
import sys
def read(): return sys.stdin.readline()


t = int(input())
nums = []
for _ in range(t):
    n = int(read())
    nums.append(n)
# 1 산술평균
print(round(sum(nums)/len(nums)))
# 2 중앙값
nums.sort()
print(nums[len(nums)//2])

# 3 최빈값
cnt = Counter(nums)
try:
    if cnt.most_common()[0][1] == cnt.most_common()[1][1]:
        print(cnt.most_common()[1][0])
    else:
        print(cnt.most_common()[0][0])
except:
    print(cnt.most_common()[0][0])
# 4 범위
print(max(nums)-min(nums))
