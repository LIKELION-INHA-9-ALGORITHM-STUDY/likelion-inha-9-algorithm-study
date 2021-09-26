# 더할건 최대한 더하고 빼면 됨 . . 
# -로 나누고 + 음... ㅜㅜ ㅡㅡㅡ..
# print(int(x[1])) 안됨 int 로 안나눠짐. 
# +로 나눈 것들을 따로 저장해야함. 

x = input().split('-') #
print(x) # ['5', '2+3'] # 각각의 값들을 더해야 한다.5-2+3
# print(type(x)) # list
# x = list(map(int, x))
# print(x)

result = 0
arr =[]
for i in x : 
    plus = i.split('+')
    for y in plus : 
        result += int(y)
        arr.append(result)
    
print(arr) #[5, 8, 11]
arr.pop()

print(arr)
print(result) #11

num = arr[0]*2
print(num)
for r in arr :
    num -= r

print(num)

