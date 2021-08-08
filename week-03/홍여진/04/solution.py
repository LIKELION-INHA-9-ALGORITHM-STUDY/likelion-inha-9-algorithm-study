#더 맵게1!!!!! 더 맵게!!!!!!!!!!!!!!!!!!
import heapq
def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while scoville[0] < K:
        try:
            f = heapq.heappop(scoville)
            s = heapq.heappop(scoville)
        except:
            return -1
        heapq.heappush(scoville,f+s*2)
        answer +=1
    return answer