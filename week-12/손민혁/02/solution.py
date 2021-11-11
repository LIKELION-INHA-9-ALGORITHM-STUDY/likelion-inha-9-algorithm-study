def solution(sizes):
    """
    1. 최소직사각형은 가로 또는 높이의 길이가 가장 큰 명함이 들어갈 수 있어야한다.
    2. 명함을 90도로 회전시키는 경우도 고려할 수 있다. ( 가로 세로가 바뀜 )
    3. 어떤 명함이 1 2번을 만족시키지 않는 경우 그 명함의 가로 세로를 기준으로 최소직사각형 늘리기
        단, 명함을 회전시키는 경우도 고려해서 최소한으로 늘리는 경우로 선택한다.

    """
    width = height = 0

    def is_fit(w, h):
        """명함의 가로 세로 길이가 최소직사각형을 만족하는지 검사"""
        if w <= width and h <= height:
            return True
        elif h <= width and w <= height:
            return True
        return False

    for w, h in sizes:
        if not is_fit(w, h):
            new_w, new_h = max(width, w), max(height, h)
            rotated_w, rotated_h = max(width, h), max(height, w)
            if new_w * new_h < rotated_w * rotated_h:
                width, height = new_w, new_h
            else:
                width, height = rotated_w, rotated_h

    return width * height
