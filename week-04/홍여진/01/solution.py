def solution(answers):
    answer = []
    f=[1,2,3,4,5]
    s=[2,1,2,3,2,4,2,5]
    t=[3,3,1,1,2,2,4,4,5,5]
    fc = sc = tc = 0 #수포자 1,2,3번이 문제를 맞출때마다 카운트
    for i in range(len(answers)):
        if answers[i] == f[i%5]: fc +=1
        if answers[i] == s[i%8]: sc +=1
        if answers[i] == t[i%10]: tc +=1
    n = 1
    for count in (fc,sc,tc):
        if count == max(fc,sc,tc):
            answer.append(n)
        n +=1
    return answer