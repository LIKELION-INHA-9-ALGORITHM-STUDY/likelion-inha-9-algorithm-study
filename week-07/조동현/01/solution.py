a, p = map(int, input().split(" "))

sequence = [a]

cur = a
while True:
    cur = sum(map(lambda n: int(n) ** p, str(cur)))
    if cur in sequence:
        print(len(sequence[:sequence.index(cur)]))
        break

    sequence.append(cur)