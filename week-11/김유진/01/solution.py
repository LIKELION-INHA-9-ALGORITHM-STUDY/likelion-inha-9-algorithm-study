def solution(arr) : 
    result =[]
    
    for i in range(len(arr)): # 인덱스 하나씩 비교 
        if i == 0 : 
            result.append(arr[i])

        if i >= 1 : 
            if arr[i-1] != arr[i] : 
                result.append(arr[i]) # 다르면 result 추가 

    return result 
