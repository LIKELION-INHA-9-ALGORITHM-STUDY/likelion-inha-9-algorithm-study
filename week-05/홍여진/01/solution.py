def solution(n, lost, reserve):
    lost.sort()
    reserve.sort()
    reserve_idx = 0
    reserve_and_lost = []  # 체육복을 도난당했지만 여벌 체육복이 있는 학생들
    for l in lost:
        if l in reserve:
            reserve_and_lost.append(l)
    for r in reserve_and_lost:  # 체육복을 도난당했지만 여벌 체육복이 있는 학생들을 lost, remove에서 제거
        lost.remove(r)
        reserve.remove(r)

    answer = n - len(lost)  # 체육복이 있는 학생들수

    for l in lost:
        for idx in range(reserve_idx, len(reserve)):
            if abs(l-reserve[idx]) == 1:  # 바로 앞번호 학생 또는 뒷번호 학생이 여벌옷이 있는 경우
                answer += 1
                reserve_idx = idx+1
                break
            elif reserve[idx] - l > 1:  # 모든 reserve 학생들이 lost학생의 바로 뒷번호보다 큰 번호를 가지므로 break
                break
    return answer
