import sys
def count_candy(line): #line에서 가장 긴 연속캔디수 return
    result = 1
    count = 1
    for i in range(len(line)-1):
        if line[i] == line[i+1]:
            count+=1
        else:
            count=1
        if result < count: result = count
    return(result)

def solution():
    read =  lambda:sys.stdin.readline().strip()
    t = int(read())
    input=[list(read()) for i in range(t)]

    #swap
    result = 1 #먹을 수 있는 사탕의 최대 개수
    for i in range(t-1):
        for j in range(t):
            #상하로 swap
            input[i][j],input[i+1][j] = input[i+1][j],input[i][j]
            a = count_candy(input[i]) #swap한 위쪽row에서 센 연속캔디수
            b = count_candy(input[i+1]) #swap한 아래쪽row에서 센 연속캔디수
            x = count_candy([list([input[k][j]]) for k in range(t)]) #swap한 col에서 센 연속캔디수
            if result<max(a,b,x): result =max(a,b,x) #result보다 더 큰 값이 있다면 대체
            input[i][j], input[i + 1][j] = input[i + 1][j], input[i][j] #restore

            #좌우로 swap
            input[j][i], input[j][i+1] = input[j][i+1], input[j][i]
            a = count_candy([list([input[k][i]]) for k in range(t)]) #swap한 왼쪽 col에서 센 연속캔디수
            b = count_candy([list([input[k][i+1]]) for k in range(t)]) #swap한 오른쪽 col에서 센 연속캔디수
            x = count_candy(input[j]) #swap한 row에서 센 연속캔디수
            if result < max(a, b, x): result = max(a, b, x) #result보다 더 큰 값이 있다면 대체
            input[j][i], input[j][i+1] = input[j][i+1], input[j][i] #restore
            if result == t: #result가 line의 길이와 같다면 최대값이므로 바로 리턴
                return(t)
    return(result)
print(solution())