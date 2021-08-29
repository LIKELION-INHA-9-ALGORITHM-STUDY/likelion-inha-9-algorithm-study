# 정답률 84.6%
def solution(n, lost, reserve):
    answer=n-len(lost)
    for i in range(len(lost)):
        for j in range(len(reserve)):
            if lost[i]==reserve[j] or lost[i]-1==reserve[j] or lost[i]+1==reserve[j]:
                answer+=1
                reserve[j]=100
                break

    return answer

# 정답률 84.6%
def solution(n, lost, reserve):
    answer=n-len(lost)
    for i in range(1,n+1):
        if i in lost:
            if i in reserve:
                reserve.remove(i)
                answer+=1
            elif i-1 in reserve:
                reserve.remove(i-1)
                answer+=1
            elif i+1 in reserve:
                reserve.remove(i+1)
                answer+=1
    return answer

# 성공한 코드 
# 위와 비슷해보이지만, 잃어버린 사람이 여벌이 있는 경우부터 비교 후 빌려주는 순
# 테스트 케이스 중, lost와 reserve가 학생 번호 순서대로 배열되어 있지 않은 경우 고려하였음
def solution(n, lost, reserve):
    answer=n-len(lost) #전체 학생수에서 잃어버린 학생수를 뺀 값
    for i in range(1,n+1): #1번 학생부터 n번 학생까지
        if i in lost: #lost 리스트에 학생이 있는경우
            if i in reserve: #reserve 리스트에서 같은 번호가 있는지, 즉 본인이 잃어버렸는지 확인 
                reserve.remove(i) #맞으면 reserve 및 lost 리스트에서 제외 - 다음 비교 시 시간 단축
                lost.remove(i) 
                answer+=1 
                
    for i in range(1,n+1):
        if i in lost:
            if i-1 in reserve: #앞 번호가 있는 경우
                reserve.remove(i-1) #reserve 리스트에서 제외하여 '중복되어 빌려주지 않도록 함'
                answer+=1
            elif i+1 in reserve: #뒷 번호가 있는 경우
                reserve.remove(i+1)
                answer+=1
    return answer