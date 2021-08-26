def solution(n, lost, reserve):
    answer = 0
    # 도난 + 여벌 학생 제거 (= 체육 수업을 들을 수 있음)
    for l in lost:
        if l in reserve:
            reserve.remove(l), lost.remove(l)
    for student in range(1, n + 1):
        if student in lost:
            # 체육복을 도난당했지만 옷을 빌려 수업을 들을 수 있음
            if student - 1 in reserve:
                reserve.remove(student - 1)
                answer += 1
            elif student + 1 in reserve:
                reserve.remove(student + 1)
                answer += 1
        else:
            # 도난 당하지 않은 학생들
            answer += 1
    return answer
