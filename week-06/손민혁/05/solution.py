def solution(triangle):
    """
    풀이: 트리를 뒤집어 역삼각형으로 만든 후, 맨 윗줄부터 그 줄의 j와 j+1번째 값 중 큰 값을 다음 줄의 j번째 값에 더한다. 맨 마지막에는 최댓값이 남음!!
    """
    triangle = triangle[::-1]
    for i, lst in enumerate(triangle):
        if len(lst) == 1:
            return lst[0]

        for j in range(len(lst) - 1):
            triangle[i + 1][j] += max(lst[j], lst[j + 1])
