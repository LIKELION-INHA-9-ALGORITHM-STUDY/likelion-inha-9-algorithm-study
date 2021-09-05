min_count = float("inf")

def work(number, count):
    global min_count

    if number == 1:
        if count < min_count:
            min_count = count
        return

    if count >= min_count: return

    if number % 3 == 0:
        work(number // 3, count + 1)

    if number % 2 == 0:
        work(number // 2, count + 1)

    work(number - 1, count + 1)


work(int(input()), 0)

print(min_count)