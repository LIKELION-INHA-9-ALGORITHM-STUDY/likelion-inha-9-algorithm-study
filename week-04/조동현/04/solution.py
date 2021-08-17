from itertools import combinations_with_replacement

def get_triangular_numbers(n):
    numbers = []
    current = 0
    last_row = 1
    while current <= n:
        current += last_row
        last_row += 1
        numbers.append(current)

    return numbers

def is_eureka(n):
    triangular_numbers = get_triangular_numbers(n)
    combs = list(combinations_with_replacement(triangular_numbers, 3))
    for c in combs:
        if sum(c) == n:
            return True

    return False

if __name__ == "__main__":
    loop = int(input())
    numbers = []

    for _ in range(loop):
        n = int(input())

        if is_eureka(n):
            print(1)
        else:
            print(0)