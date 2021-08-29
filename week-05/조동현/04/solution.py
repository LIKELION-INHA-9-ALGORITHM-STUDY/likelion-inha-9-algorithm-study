def solution(number, k):
    stack = []
    remove_count = 0

    for c in number:
        stack.append(c)

        if remove_count >= k: continue

        while (len(stack) > 1) and (stack[-2] < stack[-1]) and (remove_count < k):
            stack[-2], stack[-1] = stack[-1], stack[-2]
            stack.pop()
            remove_count += 1

    if remove_count < k:
        stack = stack[:-(k - remove_count)]

    return ''.join(stack)