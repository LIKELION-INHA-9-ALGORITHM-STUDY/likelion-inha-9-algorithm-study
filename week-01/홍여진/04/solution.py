def solution(n,a,b):
    answer = 1
    while True:
        if (abs(a-b) == 1) and (min(a,b)%2 == 1): #두 수가 나란한 수이고, 최솟값이 홀수일 때 a와 b의 대결이 이뤄짐 
            break
        answer += 1 #위 조건 만족못할때마다 라운드+1
        a = (a+1)//2 # 홀수//2 하면 다음 라운드 번호보다 1작게나오므로 +1해주고 2로 나눈 몫을 구함
        b = (b+1)//2
    return answer