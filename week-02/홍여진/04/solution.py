def solution(prices):
    answer = [0 for _ in range(len(prices))] #0으로 모두 초기화
    for i in range(len(prices)-1): #맨 마지막 주식가격은 무조건 0이므로 len(prices)-1까지
        for j in range(i, len(prices)-1): #맨 마지막 주식가격은 i보다 크든 작든 영향을 끼치지않으므로 len(prices)-1까지
            if prices[i] > prices[j]:
                break
            answer[i] += 1 
    return answer