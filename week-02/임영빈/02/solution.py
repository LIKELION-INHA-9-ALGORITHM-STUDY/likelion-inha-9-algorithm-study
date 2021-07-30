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