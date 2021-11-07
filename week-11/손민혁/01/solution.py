def solution(arr):

    """각 숫자마다 리스트의 마지막 원소와 비교하며 연속인지 체크하기"""

    answer = []
    for n in arr:
        if not answer or n != answer[-1]:
            answer.append(n)
    return answer
