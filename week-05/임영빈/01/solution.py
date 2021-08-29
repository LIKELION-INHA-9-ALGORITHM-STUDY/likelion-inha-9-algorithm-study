def solution(n, lost, reserve):
	reserve_set = set(reserve)
	lost_set = set(lost)
	reserve = reserve_set - lost_set
	lost = lost_set - reserve_set
	for r in reserve:
		if r - 1 in lost:
			lost.remove(r - 1)
		elif r + 1 in lost:
			lost.remove(r + 1)
		if len(lost) <= 0 : break
	return n - len(lost)
