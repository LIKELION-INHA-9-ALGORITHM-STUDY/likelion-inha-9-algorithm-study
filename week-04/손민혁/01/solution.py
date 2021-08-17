# student 클래스 => 학생의 정답, 점수, id로 구성
class student:
    def __init__(self, real_answer, random, id):
        share, rest = len(real_answer) // len(random), len(real_answer) % len(random)
        self.answer = random * share + [random[i] for i in range(rest)]
        self.score = sum(
            [(self.answer[i] == real_answer[i]) for i in range(len(real_answer))]
        )
        self.id = id


# 학생 3명에 대한 객체를 만들어 최고 점수를 받은 학생들을 return
def solution(answers):
    s1 = student(answers, [1, 2, 3, 4, 5], id=1)
    s2 = student(answers, [2, 1, 2, 3, 2, 4, 2, 5], id=2)
    s3 = student(answers, [3, 3, 1, 1, 2, 2, 4, 4, 5, 5], id=3)

    top_score = max(s1.score, s2.score, s3.score)
    return [student.id for student in [s1, s2, s3] if student.score == top_score]
