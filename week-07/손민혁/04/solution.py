def solution(numbers, target):
    """숫자별로 + 혹은 -의 연산을 가질 수 있기 때문에 이진 트리 구조의 DFS를 통해 모든 경우의 수를 계산해보고 target과 맞는 갯수 리턴"""
    answer = []
    res = 0

    def dfs(i, res, answer):
        l = res - numbers[i]  # - 연산을 가지는 경우
        r = res + numbers[i]  # + 연산을 가지는 경우

        # 브레이크 조건: 모든 numbers 탐색(연산)
        if i == len(numbers) - 1:
            answer.append(l)
            answer.append(r)
            return

        # 깊이 우선 탐색
        dfs(i + 1, l, answer)
        dfs(i + 1, r, answer)
        return answer

    dfs(0, res, answer)
    return answer.count(target)
