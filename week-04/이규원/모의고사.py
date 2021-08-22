def solution(answers):
    #수포자들이 찍는 순서
    one=[1,2,3,4,5]
    two=[2,1,2,3,2,4,2,5]
    three=[3,3,1,1,2,2,4,4,5,5]
    
    #idx는 각 수포자들의 찍는 순서를 파악하는 리스트 인덱스 값
    idx1=0
    idx2=0
    idx3=0
    #cnt_는 각 수포자들의 정답개수
    cnt_one=0
    cnt_two=0
    cnt_three=0
    
    for i in range(len(answers)): #문제수만큼 반복한다
        if idx1==len(one): #수포자1의 찍는 순서를 반복한다 (1,2,3,4,5,1,2..)
            idx1=0 #인덱스 값 초기화
        if one[idx1]==answers[i]: #찍은 값과 정답이 같으면 수포자1의 정답개수가 하나씩 증가한다
            cnt_one+=1
        idx1+=1 #찍었으면 다음 찍는 값 순서로 이동 
        
        if idx2==len(two): #각 수포자마다 찍는 순서의 개수가 다르모로 인덱스를 다르게 주었다
            idx2=0       
        if two[idx2]==answers[i]:
            cnt_two+=1
        idx2+=1    
        
        if idx3==len(three):
            idx3=0
        if three[idx3]==answers[i]:
            cnt_three+=1
        idx3+=1
            
    answer=[]
    candidate=[cnt_one,cnt_two,cnt_three] #candidate(후보)에 각 수포자들의 정답 개수 저장
    temp_max=max(candidate) #최대 정답 개수 저장

    for i in range(3): 
        if candidate[i]==temp_max: #수포자 3명의 정답 개수가 최대 정답 개수와 일치하면 answer 리스트에 추가한다
            answer.append(i+1)

    answer.sort() #수포자들의 번호 순서대로 정렬한다
    
    return answer