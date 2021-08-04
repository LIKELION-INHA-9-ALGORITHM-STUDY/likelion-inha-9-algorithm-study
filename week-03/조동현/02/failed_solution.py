def solution(numbers):
    for i in range(len(numbers) - 1):
        for j in range(len(numbers) - i - 1):
            n1 = str(numbers[j])
            n2 = str(numbers[j + 1])
            
            n3 = int(n1 + n2)
            n4 = int(n2 + n1)
            
            if n3 < n4:
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
                
    return ''.join(map(str,numbers))
