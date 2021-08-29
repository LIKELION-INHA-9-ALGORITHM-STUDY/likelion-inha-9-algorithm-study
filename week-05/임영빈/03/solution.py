# numbers배열에 있는 각 숫자를 answer에 넣을때마다 넣어도 되는 값인지 확인하고 넣는다.
# answer에 값을 넣을때마다 뒤에서부터 들어가는 값보다 작은 애들은 계속 pop하는거임
# return 아직 남은 제거횟수
def remove_small_in_stack(answer, number, left_count):
	while len(answer) > 0 and left_count > 0:
		if answer[-1] < number:
			answer.pop()
			left_count -= 1
		else: break
	answer.append(number)
	return left_count

def solution(numbers, k):
	answer = list()
	for number in numbers:
		k = remove_small_in_stack(answer, number, k)
	if k != 0:
		answer = answer[:-k]
	return ''.join(answer)