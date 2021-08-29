from collections import deque

def solution(people, limit):
    remains = deque(sorted(people))
    count = 0

    while len(remains) > 0:
        boat = remains.pop()

        if boat + remains[0] <= limit:
            boat += remains.popleft()

        count += 1

        if len(remains) == 1:
            count += 1
            remains.pop()

    return count