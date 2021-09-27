from collections import defaultdict

n = int(input())
p = []
for _ in range(n):
    p.append(list(map(int, input().split())))

answer = defaultdict(int)


def is_same(p, i, j, n):
    """색종이가 모두 같은 수로 이루어져 있는지 체크"""
    num = p[i][j]
    for a in range(n):
        for b in range(n):
            if p[i + a][j + b] != num:
                return False
    return True


def devide(p, i, j, n):
    """종이 전체가 같은 수로 이루어져 있는지 check 후 딕셔너리에 카운트 추가, 그렇지 않으면 9등분해서 다시 재귀 돌리기"""
    if is_same(p, i, j, n):
        answer[p[i][j]] += 1
    else:
        for a in range(3):
            for b in range(3):
                devide(p, i + a * n // 3, j + b * n // 3, n // 3)


devide(p, 0, 0, n)
for a in [-1, 0, 1]:
    print(answer[a])
