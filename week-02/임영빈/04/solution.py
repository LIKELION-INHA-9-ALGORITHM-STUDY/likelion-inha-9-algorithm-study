def solution(prices):
    answer = list()
    for i, price in enumerate(prices):
        time = 0
        for j in range(i + 1 ,len(prices)):
            time += 1
            if price > prices[j]:
                break
        answer.append(time)
    return answer