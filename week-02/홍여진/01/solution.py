def solution(nums):
    choice = len(nums)/2 #뽑을 수 있는 포켓몬수 아니 폰켓몬 ... N/2
    num = len(set(nums)) #set으로 만들어서 중복제거후 길이 == 중복되지않는 폰켓몬 개체수
    return min(choice,num) # 둘 중 더 작은 수 출력