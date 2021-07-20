#### 210719 멋사 코테 스터디 1주차 - HASH

## 자료구조 : data들의 모임, 관계, 함수 등 집합이자 사용 편하게 저장해 놓은 형태
# 자료구조를 잘 선택하자 -> 자료를 찾고 꺼내오기 쉽도록 잘 규칙을 만들자 

## Hash 
# 임의의 크기를 가진 데이터(Key)를 고정된 길이, 크기의 데이터(Value)로 변환시켜 저장하는 것
# Hash Table : Key에 데이터(Value)를 저장하는 데이터 구조 (직접 접근 가능)
# Array 구조임 
# key를 통해 바로 data를 받아옴 -> 속도가 획기적으로 빨라짐
# 하나하나 찾는 Linear Search O(N)보다 빠름 -> O(1) = constant time
# 보통 배열로 미리 Hash Table 사이즈만큼 생성 후 사용
# 파이썬은 dictionary 타입을 사용하면 됨 -> 별도로 hash 구현 필요 없음
# JS는 Object

# Hashing function : key에 대한 산술연산을 이용하 data 위치를 찾을 수 있는 함수
# 문자열 string을 받아서 숫자로 반환해주는 함수 -> 숫자가 바로 index
# ex) pizza -> Hash function -> 단어 길이 5 -> index 5번에 가격 value 저장
# Hash Collision : 단어수 같은 걸 넣었는데 value 값 달라서 충돌 
# -> 내부에 List를 만들어서 저장 후 거기서 하나하나 탐색하는 Linear Search ON



## 문제 1. 완주하지 못한 선수

def solution(participant, completion):
    dict = {} # 빈 dictionary형 data
    for x in participant : 
        dict[x] = dict.get(x,0)+1 # 해당 key가 없으면 0 반환 (현재 모두 1)
        
    for x in completion :
        dict[x] = dict.get(x,0)-1 # 완주하면 (해당 key 있으면) 1-1 = 0
        
    for answer, x in dict.items(): # .items으로 key, value 한꺼번에 for문 반복
        if x != 0 : # 완주 못한 사람
            return answer 