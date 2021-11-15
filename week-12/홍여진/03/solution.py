import sys
n = int(sys.stdin.readline().strip())
temp = []
for _ in range(n):
    temp.append(int(sys.stdin.readline().strip()))
temp.sort()
answer = 0
for i in range(1, n+1):
    answer += abs(i-temp[i-1])
print(answer)
