import sys

n = int(sys.stdin.readline())
list_x = list(map(int, sys.stdin.readline().split()))  # 오리지날 리스트

sorted_x = sorted(list(set(list_x)))  # 오리지날에서 중복 제거 + 오름차순 정렬

answer = {}
for i in range(len(sorted_x)):
    answer[sorted_x[i]] = i  # 오름차순으로 정렬된 원소의 인덱스가 좌표 압축의 결과값

for a in list_x:
    print(answer[a], end=" ")
