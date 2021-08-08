#한 케이스에서 런타임 에러가 뜬 코드(정답률 93.8%)
def solution(citations):
    citations.sort()
    for i in range(len(citations)):
        if citations[i]>=len(citations)-i:
            answer=len(citations)-i
            break
    return answer

# answer=0을 추가하였더니 바로 통과..
def solution(citations):
    answer=0
    citations.sort()
    for i in range(len(citations)):
        if citations[i]>=len(citations)-i:
            answer=len(citations)-i
            break
    return answer

