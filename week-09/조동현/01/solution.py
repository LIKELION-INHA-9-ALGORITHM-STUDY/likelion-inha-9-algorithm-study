n = int(input())
target = list()

for _ in range(n):
    target.append(int(input()))

q = list(range(n, 0, -1))
stack = list()

result = list()
calculations = list()

success = True

pointer = 0
while len(q) > 0:
    if len(stack) == 0:
        stack.append(q.pop())
        calculations.append("+")
        continue

    if stack[-1] == target[pointer]:
        result.append(stack.pop())

        if result[pointer] != target[pointer]:
            success = False
            break

        pointer += 1
        calculations.append("-")

    else:
        stack.append(q.pop())
        calculations.append("+")


if success:
    for c in calculations:
        print(c)
    
    for _ in stack:
        print("-")
        # calculations.append("-")
else:
    print("NO")