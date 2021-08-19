def solution(brown, yellow):
    for i in range(1,yellow+1):
        if yellow%i ==0:
            if brown == 2*i+2*int(yellow/i)+4:
                return[int(yellow/i)+2, i+2]