from itertools import permutations
def check_prime(num):
    if num <2:
        return False
    for i in range(2,num):
        if num%i ==0:
            return False
    return True

def solution(numbers):
    answer = 0
    numbers = [num for num in numbers]
    #per = [list(permutations(numbers, i)) for i in range(1, len(numbers) + 1)] # [[('1',), ('7',)], [('1', '7'), ('7', '1')]]
    per_numbers = []
    for i in range(1,len(numbers)+1):
        per_numbers += list(permutations(numbers,i)) #[('1',), ('7',), ('1', '7'), ('7', '1')]

    numbers = set([int(('').join(num)) for num in per_numbers])
    for num in numbers:
        if check_prime(num):
            answer +=1
    return answer