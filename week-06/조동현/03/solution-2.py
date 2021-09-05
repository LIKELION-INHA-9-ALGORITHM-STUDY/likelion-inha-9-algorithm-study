test_case_count = int(input())
test_cases = list()

for _ in range(test_case_count):
    test_cases.append(int(input()))

for test_case in test_cases:
    l = [1, 2, 4]
    if test_case < 4:
        print(l[test_case - 1])
        continue

    for _ in range(test_case - 3):
        l.append(l[-1] + l[-2] + l[-3])

    print(l[-1])