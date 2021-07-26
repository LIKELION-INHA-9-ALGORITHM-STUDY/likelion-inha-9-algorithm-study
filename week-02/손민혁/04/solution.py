def solution(prices):
    answer = []
    # i 와 j의 투 포인터 
    for i in range(len(prices)):
        cur_price = prices[i]
        duration = 0
        
        # j는 i+1부터 탐색하며 가격이 떨어지지 않은 기간 측정
        for j in range(i+1,len(prices)):
            if prices[j] >= cur_price:
                duration += 1
            else:
                duration += 1
                break
        answer.append(duration)
    return answer