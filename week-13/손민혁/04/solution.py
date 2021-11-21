import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
target = str(sys.stdin.readline())

e = 0  # 포인터
answer = 0  # 출력할 정답

while e < m:
    if target[e] == "I":  # 현재 위치의 문자가 'I' 이면 탐색 시작
        cnt = 0
        for i, c in enumerate(target[e:]):  # 현 위치부터 탐색하면서 'IOIOI..' 를 만족하는지 검사
            if cnt >= 2 * n + 1:  # 찾으려는 IOI...를 찾았다면 'OI'를 지우고 I... 부터 다시 만족하는지 찾음
                answer += 1
                cnt -= 2

            if i % 2 == 0 and c == "I":
                cnt += 1
            elif i % 2 == 1 and c == "O":
                cnt += 1
            else:
                e = e + i - 1
                break
    e += 1

print(answer)
