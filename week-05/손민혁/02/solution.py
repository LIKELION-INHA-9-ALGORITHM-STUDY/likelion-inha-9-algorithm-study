def solution(name):
    """
    풀이
    1. 현 위치에서 수정해야할 문자의 위치 탐색 후 이동 => position_check
    2. 수정해야할 문자의 최단 거리 탐색 후 이동 => char_check

    주석(?)
    #1. 아스키 코드 = {A:65, B:66, ... , Z:90}
    #2. 왼쪽 끝에서 오른쪽 끝으로, 오른쪽 끝에서 왼쪽 끝으로 넘어갈 때를 위해 나머지(%) 사용
    #3. name과 비교 및 수정을 위해 my_answer를 list로 설정
    """

    def char_check(alphabet):

        """목표 알파벳까지 최단 거리 리턴(조이스틱 위아래 이동)"""

        move = ord(alphabet) - ord("A")  # 1
        if move <= 13:
            # 순방향 이동 (A,B,C,...)
            return move
        else:
            # 역방향 이동 (A,Z,Y,X,...)
            return 26 - move

    def position_check(cur_index, my_answer):

        """
        다음 수정해야할 알파벳 위치 탐색
        return( 다음 목표의 위치, 이동 거리 )
        CASE 1. 현재 위치의 알파벳 수정 필요
        CASE 2. 오른쪽으로 이동하며 최단 거리 탐색
        CASE 3. 왼쪽으로 이동하며 최단 거리 탐색
        """

        # CASE 1
        if my_answer[cur_index] != name[cur_index]:
            return 0, 0

        r = l = cur_index
        r_cnt = 1
        l_cnt = -1
        for _ in range(len(name) // 2):
            r = (cur_index + r_cnt) % len(name)  # 2
            l = (cur_index + l_cnt) % len(name)
            # CASE 2
            if my_answer[r] != name[r]:
                return r, r_cnt
            # CASE 3
            if my_answer[l] != name[l]:
                return l, l_cnt
            r_cnt += 1
            l_cnt -= 1

    ans = 0
    my_answer = ["A"] * len(name)  # 3

    i = 0
    while "".join(my_answer) != name:
        i, count = position_check(i, my_answer)
        ans += abs(count)
        if my_answer[i] != name[i]:
            ans += char_check(name[i])
            my_answer[i] = name[i]
    return ans
