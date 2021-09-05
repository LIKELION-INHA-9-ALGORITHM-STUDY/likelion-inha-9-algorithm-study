# 1, 2, 4, 7, 13, 24 ... 
# 점화식 : fn = f(n-1) + f(n-2) + f(n-3)

num = int(input())

def result(n) : 
    if n == 1 : 
        return 1
    elif n == 2 : 
        return 2 
    elif n == 3 : 
        return 4 
    else : 
        return result(n-1) + result(n-2) + result(n-3)

for i in range(num) : 
    n = int(input())
    print(result(n))
