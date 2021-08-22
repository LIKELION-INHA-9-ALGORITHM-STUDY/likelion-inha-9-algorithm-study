def solution(answers):
	# 필요한 변수들
	res = list()
	stupid1 = (1, 2, 3, 4, 5)
	stupid2 = (2, 1, 2, 3, 2, 4, 2, 5)
	stupid3 = (3, 3, 1, 1, 2, 2, 4, 4, 5, 5)
	len1 = len(stupid1)
	len2 = len(stupid2)
	len3 = len(stupid3)
	scores = [0, 0, 0]
	max_score = 0
	
	# 문제 맞춘 개수 세기
	for i, answer in enumerate(answers):
		scores[0] += (stupid1[i%len1] == answer)
		scores[1] += (stupid2[i%len2] == answer)
		scores[2] += (stupid3[i%len3] == answer)
	max_score = max(scores)
	
	# 가장 많이 맞춘사람 list에 추가
	for i, score in enumerate(scores):
		if score == max_score : res.append(i + 1)
	return res