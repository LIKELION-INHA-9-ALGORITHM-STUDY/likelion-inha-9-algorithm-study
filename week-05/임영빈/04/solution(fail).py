# 의식의 흐름대로 작성한코드..
# 테스트케이스는 모두 통과했지만 시간테스트는 모두 fail..

def solution(people, limit):
	people.sort()
	count = 0
	check = 0
	while(len(people) > 0):
		for j in reversed(range(len(people))):
			temp = people[j]
			temp2 = people[0]
			print(f"0 : {0} j : {j} people : {temp + temp2} left people: {len(people)}")
			if 0 >= j : break
			if temp + temp2 <= limit:
				people.remove(temp)
				people.remove(temp2)
				print("count가 1회 증가 두명태움")
				count += 1
				check = 1
				break
		if check == 0:
			print("count가 1회 증가 한명태움")
			people.remove(temp2)
			count += 1
		check = 0
	return count

print(solution([40, 50, 150, 160],200)) #결과 2
print(solution([70, 50, 80, 50], 100)) #결과 3