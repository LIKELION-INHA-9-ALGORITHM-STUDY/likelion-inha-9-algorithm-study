def solution(n):
    q = n # 몫

    r_list = []

    while q > 0:
        r = q % 3
        q = q // 3

        r_list.insert(0, r)

    trinary = []
    if q > 0: trinary = [q]

    trinary.extend(r_list)
    # 3진법으로 변환

    for i in range(len(trinary) - 1):
        cursor = - (i + 1)
        if trinary[cursor] <= 0:
            trinary[cursor - 1] = trinary[cursor - 1] - 1
            trinary[cursor] = trinary[cursor] + 3
    # 0, 1, 2 3진법을 1, 2, 3 3진법으로 변환

    return (str(int("".join(map(str, trinary)).replace("3", "4"))))
    # 3을 4로 치환