def solution(participant, completion):
    participant.sort()
    completion.sort()
    i = 0
    answer = ''
    for c in completion:
        if c != participant[i]:
            answer = participant[i]
            #둘 다 정렬했는데 c(completion[i])와 participant[i]가 다르면 completion에 participant[i]가 없는거니까 answer = participant[i]
            break
        i = i + 1
    if answer == '':
        #answer에 아무것도 들어가지않았다면 모든 c가 participant[i]와 동일 == participant의 마지막 원소가 answer
        answer = participant[-1]
    return answer
