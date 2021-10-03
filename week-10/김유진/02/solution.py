# 첫째 줄 : 사이트 주소 수, 비밀번호 찾으려는 사이트 주소 수 
# 사이트 주소, 비밀번호 > 공백 구분 
# 사이트 주소 : 알파벳, -, . 
# 비밀번호 : 알파벳 대문자
# 최대 길이 20 

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
dic = {}

for _ in range(N):
    adress, password = input().split()
    dic[adress] = password

for _ in range(M):
    print(dic[input().rstrip()])