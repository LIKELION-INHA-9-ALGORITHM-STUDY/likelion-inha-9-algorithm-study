# Fn = Fn-1 + Fn-2 (n ≥ 2)
# 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597


n = int(input())
array =[]

num = 0 

for i in range(n+1) : 
    if i == 0 : 
        num = 0 
    elif i <= 2 : 
        num = 1
    else : 
        num = array[-1] + array[-2]
    array.append(num)

print(array[-1])
