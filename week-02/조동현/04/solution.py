def solution(prices):
    ret = []

    for i, cur_price in enumerate(prices):
        s = 0
        for j in range(i + 1, len(prices)):
            s += 1
            if cur_price > prices[j]:
                break
        ret.append(s)

    return ret