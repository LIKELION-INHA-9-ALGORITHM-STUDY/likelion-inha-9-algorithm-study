def list_safe_get(l, i):
    if i < 0: return None
    if i >= len(l): return None
    
    return l[i]

def solution(n, lost, reserve):
    students = list(
        map(lambda s: 2 if s in reserve else 1, list(range(1, n + 1)))
    ) # 원래 체육복 보유수로 학생 초기화
    
    for i, s in enumerate(students):
        if (i + 1) in lost: students[i] -= 1
    # 체육복 도난
    
    for i, s in enumerate(students):
        prev_student = list_safe_get(students, i - 1)
        next_student = list_safe_get(students, i + 1)
        
        if students[i] >= 2 and prev_student == 0:
            students[i] -= 1
            students[i - 1] += 1
            
        if students[i] >= 2 and next_student == 0:
            students[i] -= 1
            students[i + 1] += 1
    # 좌우로 체육복 없으면 빌려주기
    
    result = len(list(filter(lambda s: s > 0, students)))
    # 최종적으로 체육복이 있는 학생 수 세기
    
    return result