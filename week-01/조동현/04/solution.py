def solution(n,a,b):
    arr = list(range(1, n + 1))
    
    count = 0
    while len(arr) >= 2:
        count += 1
        
        survive = []
        for i in range(1, len(arr), 2):
            left = arr[i - 1]
            right = arr[i]

            if (left == a and right == b) or (left == b and right == a):
                return count

            if left != a and left != b and right != a and right != b:
                survive.append(left)
            else:
                if left == a or left == b:
                    survive.append(left)
                elif right == a or right == b:
                    survive.append(right)
        
        arr = survive
        
    return count