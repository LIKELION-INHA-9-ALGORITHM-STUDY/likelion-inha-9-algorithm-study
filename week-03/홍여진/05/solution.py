import heapq
def solution(operations):
    min_heap = []
    max_heap = [] #그냥 ... max값 구하려고 max_heap을 아예 만들었어요 ㅋ ㅋ ㅋ ...
    for o in operations:
        o = o.split(" ")
        if o[0] == 'I':
            num = int(o[1])
            heapq.heappush(min_heap,num)
            heapq.heappush(max_heap,-num) # -곱해서 큰 수가 앞에 오게 정렬했습니다 , , ,
        else:
            if len(min_heap) == 0:
                pass
            elif o[1] == '-1':
                min = heapq.heappop(min_heap)
                max_heap.remove(-min)
            elif o[1] == '1':
                max = heapq.heappop(max_heap)
                min_heap.remove(-max)
    if min_heap:
        return [-heapq.heappop(max_heap),heapq.heappop(min_heap)]
    else:
        return[0,0]