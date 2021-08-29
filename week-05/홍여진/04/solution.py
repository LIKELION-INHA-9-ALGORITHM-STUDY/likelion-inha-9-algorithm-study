def solution(people, limit):
    answer = 0
    people.sort()
    min_idx = 0
    max_idx = len(people) - 1
    while max_idx >= min_idx:
        if people[min_idx] + people[max_idx] <= limit:  # 최솟값 + 최댓값이 limit 이하라면
            min_idx += 1  # 두 명을 같이 내보낸다
        max_idx -= 1  # 최솟값 + 최댓값이 limit보다 크다면 최댓값 혼자만 내보낸다
        answer += 1
    return answer
