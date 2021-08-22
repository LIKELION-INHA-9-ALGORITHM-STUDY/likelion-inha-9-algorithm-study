def solution(brown, yellow):
    def get_size(num):

        """인수분해(?) => (가로 x 세로)들의 리스트 구하기"""

        sizes = []
        if num == 1:
            return [(1, 1)]
        for i in range(1, num):
            if num % i == 0:
                # 중복 제거하기
                size = (max(i, num // i), min(i, num // i))  # size: (가로, 세로)
                if size not in sizes:
                    sizes.append(size)
        return sizes

    for width, height in get_size(brown + yellow):
        for w, h in get_size(yellow):
            if width >= w + 2 and height >= h + 2:
                # 갈색 타일이 노란색 타일을 둘러 싸고 있어야 함 == (전체 타일의 가로, 세로 >= 노란색 타일의 가로, 세로 +2)
                return (width, height)
