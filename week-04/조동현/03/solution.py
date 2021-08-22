def solution(brown, yellow):
    for inner_h in range(1, yellow + 1):
        if yellow % inner_h == 0:
            inner_w = yellow // inner_h
            brown_count = (inner_h + 1) * 2 + (inner_w + 1) * 2

            if brown_count == brown:
                return [inner_w + 2, inner_h + 2]