chars = input()


def solution(chars):
    """
    풀이: "-"가 등장하면 부호(flag)를 -로 바꾸고 정답에서 하염없이 뺀다.
    """
    ans = 0
    s = ""
    flag = 1
    for char in chars:
        if char.isdigit():
            if s == "0":  # 처음부터 0이 나오면 대체 해주기
                s = char
            else:
                s += char  # 다음 부호가 나올때까지 문자를 연결해서 숫자를 만든다.
        else:
            ans += flag * int(s)
            s = ""
            if char == "-":
                flag = -1
    ans += flag * int(s)
    return ans


print(solution(chars))
