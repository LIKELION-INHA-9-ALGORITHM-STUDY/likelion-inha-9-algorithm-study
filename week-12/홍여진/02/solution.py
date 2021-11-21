def solution(sizes):
    for i in sizes:
        if i[0] < i[1]:
            i[0], i[1] = i[1], i[0]
    w = [i[0] for i in sizes]
    h = [i[1] for i in sizes]
    return max(w) * max(h)
