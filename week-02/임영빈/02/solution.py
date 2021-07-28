# (progresses[], speeds[]) => {
#	progress%만큼 되어있는 일이 speed속도로 진행돼서 100%가 될때
#	맨앞에 있는 일 기준으로 처리되는 일들의 개수를 answer[]에 추가 
#	return (answer[])
# }

import math

def solution(progresses, speeds):
	answer = list()
	work_len = len(progresses)
	count = 1
	max = math.ceil((100 - progresses[0])/speeds[0])
	for i in range(1, work_len):
		day = math.ceil((100 - progresses[i])/speeds[i])
		if day <= max:
			count += 1
		else:
			answer.append(count)
			max = day
			count = 1
	answer.append(count)
	return answer