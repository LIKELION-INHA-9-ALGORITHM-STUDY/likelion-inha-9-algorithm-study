def solution(array, commands):
    return [sorted(array[start-1:end])[target-1] for start, end, target in commands]

numbers = [3, 30, 34, 5, 9,3666,3665,366,3662,3667,311,3221,3115,3110,3113]

import heapq

answer = ""
max_len = len(str(max(numbers)))
print(max_len)
heap = []
for num in numbers:
    num = str(num)
    original_num = num
    while len(num) < max_len:
        num += num[0]
    heapq.heappush(heap,(-int(num),original_num))
while heap:
    h = heapq.heappop(heap)
    print(h)
    answer += h[1]
print(answer)

