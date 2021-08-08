def solution(array, commands):
    l=len(commands)
    answer=[]
    for i in range(l):
        idx_start=commands[i][0]-1
        idx_end=commands[i][1]-1
        new_arr=array[idx_start:idx_end+1]
        new_arr.sort()
        answer.append(new_arr[commands[i][2]-1])
    return answer