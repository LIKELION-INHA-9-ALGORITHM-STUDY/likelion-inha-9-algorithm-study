def solution(n, times):
    """
    풀이: 이진 탐색으로 최소 시간 찾기
    최댓값은 가장 심사시간이 짧은 시간의 n배 (심시시간이 가장 짧은 사람이 결국 가장 마지막에 끝날 것이기 때문)
    총 심사 가능한 사람 >= 대기 중인 n명이면 결과값을 저장해 놓은 후 최솟값을 찾는다.
    """
    answer = 0
    a, b = 1, min(times) * n
    while a <= b:
        m = (a + b) // 2
        cnt = 0  # 총 심사한 사람 카운트
        for time in times:
            cnt += m // time
        if cnt >= n:  # 총 심사한 사람이 대기하는 n명 보다 크면 결과값을 저장
            answer = m
            b = m - 1
        else:
            a = m + 1
    return answer
