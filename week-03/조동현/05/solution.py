import heapq

def pop_max(heap):
    if len(heap) == 1:
        return heap.pop()
    elif len(heap) >= 2:
        if (heap[-1] >= heap[-2]): return heap.pop(-1)
        elif (heap[-1] < heap[-2]): return heap.pop(-2)

def solution(operations):
    heap = []
    
    while len(operations) > 0:
        operation = operations.pop(0)
        opcode = operation.split(" ")[0]
        operand = int(operation.split(" ")[1])
        
        if opcode == "D" and len(heap) <= 0:
            continue
        
        if opcode == "I":
            heapq.heappush(heap, operand)
        elif opcode == "D":
            if operand == -1:
                heapq.heappop(heap)
            elif operand == 1:
                pop_max(heap)

    if len(heap) == 0: return [0, 0]
    else:
        min = heap[0]
        max = pop_max(heap)
        return [max, min]
        