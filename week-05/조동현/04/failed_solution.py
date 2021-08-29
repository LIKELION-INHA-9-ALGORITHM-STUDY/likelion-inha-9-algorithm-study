def remove_at(s, i):
    result = s[:i] + s[i + 1:]
    return result

def solution(number, k):
    remove_count = 0

    while remove_count < k:
        removed = False
        for i, c in enumerate(number):
            if c == "9": continue

            if i < len(number) - 1:
                if number[i] < number[i + 1]:
                    number = remove_at(number, i)
                    remove_count += 1
                    removed = True
                    break

        if not removed:
            number = number[:len(number) - k - remove_count]
            break

    return number