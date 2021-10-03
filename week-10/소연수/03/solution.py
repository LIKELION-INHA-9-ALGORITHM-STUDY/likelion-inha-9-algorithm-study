import sys

n, m = map(int, sys.stdin.readline().split())
dic = {} # 주소를 key, 비밀번호를 value로 갖는 딕셔너리

for i in range(n):
    address, pw = sys.stdin.readline().split()
    dic[address] = pw # 딕셔너리에 담기

for i in range(m):
    print(dic[sys.stdin.readline().rstrip()]) # 주소 입력받아 비밀번호 출력