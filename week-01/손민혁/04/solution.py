def solution(n,a,b):

    """ 최대 라운드 수 구하기 (n이 16이면 최대 라운드 수는 4) """
    
    max_rounds = 0
    t = n
    while t != 1:
        t = t/2
        max_rounds += 1

    # 대진 리스트 (n이 16이면 1~16)
    rounds = range(1,n+1)

    while True:
        # 대진을 반으로 나누기
        part1 = [i for i in rounds][:int(n/2)]
        part2 = [i for i in rounds][int(n/2):]

        # a와 b가 서로 다른 파트에 있으면 대진의 최대 라운드에서 만남
        if a in part1 and b in part2 or b in part1 and a in part2:
            return max_rounds
        
        # a와 b가 같은 파트에 있으면 대진을 해당 파트로 할당하고 최대 라운드 수도 -1
        elif a in part1 and b in part1:
            rounds = part1
            max_rounds -= 1
        elif a in part2 and b in part2:
            rounds = part2
            max_rounds -= 1

        n = int(n/2)
