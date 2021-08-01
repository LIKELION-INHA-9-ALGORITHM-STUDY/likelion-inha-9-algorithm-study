def solution(prices):
    answer = [0]*len(prices)    #리스트 개수만큼의 0을 요소로 가짐
    for i in range(0,len(prices)):
        for j in range(i+1,len(prices)):     #다음 인덱스값부터 끝까지 비교
            if prices[i]<=prices[j]:    #주식 가격이 하락하지 않은 경우 1초 더하고 다음 인덱스로
                answer[i]+=1 
            else:
                answer[i]+=1    #주식 가격이 하락한 경우 1초 더하고 다음 주식 가격으로 이동 
                break
    return answer