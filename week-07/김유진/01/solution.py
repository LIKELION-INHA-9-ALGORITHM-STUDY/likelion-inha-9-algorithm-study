# 변수1, 변수2 = input('문자열').split('기준문자열')
# index 함수 

A, P = map(int, input().split())
array = [A]
i = 0

def result(x) : 
    x = int(x) ** P 
    return x

    
while True :
    i += 1
    num = sum(map(result, str(array[i-1])))
    if num in array :
        break
    array.append(num)

print(array.index(num))