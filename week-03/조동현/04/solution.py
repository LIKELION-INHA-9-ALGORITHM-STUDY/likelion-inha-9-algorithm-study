import heapq

def solution(scoville, K):
    hq = scoville
    heapq.heapify(hq)
        
    count = 0
    while hq[0] < K:
        if len(hq) < 2: return -1
        n1 = heapq.heappop(hq)
        n2 = heapq.heappop(hq)
        
        heapq.heappush(hq, n1 + (n2 * 2))
        count += 1
    
    return count
