test_case_count = int(input())
test_cases = list()

for _ in range(test_case_count):
    test_cases.append(int(input()))

for test_case in test_cases:
    cases = list()

    def recursion(numbers):
        global cases

        s = sum(numbers)

        if s == test_case:
            cases.append(numbers)
            return

        if s + 1 <= test_case: recursion(numbers + [1])
        if s + 2 <= test_case: recursion(numbers + [2])
        if s + 3 <= test_case: recursion(numbers + [3])

    recursion([])
    print(len(cases))