PATTERN = [
    [1,2,3,4,5],
    [2,1,2,3,2,4,2,5],
    [3,3,1,1,2,2,4,4,5,5]
]

def solution(answers):
    score = [0, 0, 0]

    for i, a in enumerate(answers):
        for j, s in enumerate(score):
            answer = PATTERN[j][i % len(PATTERN[j])]
            score[j] += answer == a

    max_score = max(score)
    ret = list(i[0] + 1 for i in filter(lambda s: s[1] == max_score, enumerate(score)))

    return ret