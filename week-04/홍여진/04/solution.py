from itertools import combinations_with_replacement
import sys

def solution():
    read = lambda:sys.stdin.readline()
    t = int(read())
    input=[int(read()) for i in range(t)]
    for k in input:
        triangle = []
        
        # 삼각수들 구하기 
        for n in range(1,46):
            if n*(n+1)/2>=k: break
            triangle.append(int(n*(n+1)/2))

        # 자연수 k를 3개의 삼각수합으로 나타낼 수 있는지 검사 
        for cwr in combinations_with_replacement(triangle, 3):
            output=0
            if k == sum(cwr):
                output =1
                break
        print(output)

solution()