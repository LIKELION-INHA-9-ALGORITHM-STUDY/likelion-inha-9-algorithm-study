#brown의 개수가 훨씬 적으므로 brown부터 확인
#역으로 너비x높이가 yellow 개수와 일치하면 정답

def solution(brown, yellow):
    answer=[]
    new=(brown-4)/2 #각 모서리 제외하고 2로 나누면 new=width+height
    h=1 #height 초기값
    w=1 #width 
    while(h<=w): #width가 height보다 크거나 같은 조건 반영
        w=new-h 
        if w*h==yellow:
            answer=[w+2,h+2]
            break
        else:
            h+=1
    return answer