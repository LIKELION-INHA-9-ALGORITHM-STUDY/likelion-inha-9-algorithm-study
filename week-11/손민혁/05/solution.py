import sys

target = int(sys.stdin.readline())
t = int(sys.stdin.readline())
if t == 0:  # 고장난 버튼 없음
    print(min(len(str(target)), abs(target - 100)))  # 버튼 누르기 vs + - 로 채널 이동

elif t == 10:  # 모든 버튼이 고장남
    sys.stdin.readline().split()
    print(abs(target - 100))
else:
    btns = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]  # 사용 가능한 버튼들
    for c in list(map(int, sys.stdin.readline().split())):
        btns.remove(c)  # 고장난 버튼들 제거

    answers = [abs(target - 100)]
    up_num = down_num = target  # 목표값으로부터 각각 +1 ,-1씩 이동하면서 버튼 체크
    while True:
        up_cnt = down_cnt = 0

        num = str(down_num)  # -1씩 이동
        for n in num:
            if down_num < 0 or int(n) not in btns:
                break
            else:
                down_cnt += 1  # 자리수 하나 확인할때마다 카운트 += 1

        if down_cnt == len(num):  # 모든 숫자들이 고장나지 않은 버튼인지 확인
            answers.append(len(num) + abs(down_num - target))
            break

        num = str(up_num)  # +1씩 이동
        for n in num:
            if int(n) not in btns:
                break
            else:
                up_cnt += 1

        if up_cnt == len(num):
            answers.append(len(num) + abs(up_num - target))
            break
        up_num += 1
        down_num -= 1
    print(min(answers))  # 최솟값 리턴
