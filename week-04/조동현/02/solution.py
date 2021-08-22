from math import sqrt
from itertools import permutations


def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True

    root = sqrt(n)
    for i in range(2, int(root) + 2):
        if n % i == 0:
            return False

    return True


def solution(numbers):
    perms = []
    for i in range(1, len(numbers) + 1):
        perms.extend(int(''.join(n)) for n in
                     list(permutations(numbers, i)))

    prime_numbers = set()
    for n in perms:
        if is_prime(n):
            prime_numbers.add(n)

    return len(prime_numbers)