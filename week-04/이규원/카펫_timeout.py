#시간 초과나서 정답률 38.5% 받은 코드
#yellow 개수부터 접근하여 brown이 둘러싸는 구조면 정답이 되도록 하였다 
#yellow개수가 2,000,000의 큰 숫자이므로 시간 초과
#소수를 찾는 것과 유사하게 구현하였다

def solution(brown, yellow):
    i=2
    answer = []
    while(i<=yellow):
        if yellow%i==0: 
            div=yellow/i
            if div+i+2==brown/2: #brown이 yellow를 둘러싸는지 확인
                answer=[div+2,i+2]
                break
        else:
            i+=1   
    answer.sort(reverse=True) #너비가 높이보다 크거나 같으므로 내림차순으로 정렬
    return answer
