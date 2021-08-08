def compare(n1, n2):
    n3 = int(str(n1) + str(n2))
    n4 = int(str(n2) + str(n1))
    if n3 > n4: return "left"
    if n3 < n4: return "right"
    return "same"

def quick_sort(a, left, right):
    pl = left
    pr = right
    pivot = a[(left + right) // 2]
    
    while pl <= pr:
        while compare(a[pl], pivot) == "left": pl += 1
        while compare(a[pr], pivot) == "right": pr -= 1
        
        if pl <= pr:
            a[pl], a[pr] = a[pr], a[pl]
            pl += 1
            pr -= 1
        
    if left <= pr: quick_sort(a, left, pr)
    if pl <= right: quick_sort(a, pl, right)
    
def solution(numbers):
    quick_sort(numbers,0, len(numbers) - 1)
    return str(int(''.join(map(str, list(numbers)))))

