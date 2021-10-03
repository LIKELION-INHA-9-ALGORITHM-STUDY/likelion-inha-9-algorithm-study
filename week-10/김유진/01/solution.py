from collections import Counter
import statistics

n = int(input())
arr =[]
for i in range(n) :
    x = int(input())
    arr.append(x)

arr.sort()
print(arr)
# 산술평균 

average = int(sum(arr)/n)
print(average)

# 중앙값 
mid = statistics.median(arr)
print(mid)

# 최빈값 
k = Counter(arr).most_common()

if len(arr) > 1 : 
    if k[0][1] == k[1][1] :
        print(k[1][0]) # 두번째 작은 것
    else : 
        print(k[0][0])
else :
    print(arr[0])

# 범위 
ran = arr[-1] - arr[0] 
print(ran)