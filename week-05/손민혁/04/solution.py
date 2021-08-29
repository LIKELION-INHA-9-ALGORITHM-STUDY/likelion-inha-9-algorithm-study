from collections import deque


def solution(people, limit):
    """
    효율성 테스트 통과를 위해 deque를 이용했습니다(최대한 안쓰고 싶었지만 ㅠㅠ)

    가장 무게가 많이 나가는 사람을 먼저 보트에 태움 => first_save
    가장 무게가 적은 사람부터 보트의 남은 무게가 40 이상이면 더 태울 수 있음
    """
    answer = 0
    people.sort()
    people = deque(people)
    while people:
        first_save = people.pop()
        rest = limit - first_save
        while people and rest >= 40:
            if rest - people[0] >= 0:
                rest -= people.popleft()
            else:
                break

        answer += 1

    return answer
