def solution(prices):
    len_price = len(prices)
    answer = list()
    for i, price in enumerate(prices):
        time = 0
        # 만약 prices가 [1,2,3,1,3]이었다면
	    # 1이랑 2,3,1,3 비교 그 다음엔,
	    # 2랑 3,1,3 비교
        for j in range(i + 1 ,len_price):
            time += 1
            if price > prices[j]:
                break
        answer.append(time)
    return answer