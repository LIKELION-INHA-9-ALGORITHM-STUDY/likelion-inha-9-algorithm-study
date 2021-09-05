n1, n2 = 0, 1
for _ in range(int(input()) - 1):
    n1, n2 = n2, n1 + n2

print(n2)