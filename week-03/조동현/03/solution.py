def get_greater_count(arr, target):
    return sum([ target <= n for n in arr ])

def solution(citations):
    sorted_citations = sorted(citations)
    
    h = 0
    for _ in sorted_citations:
        if h + 1 > get_greater_count(sorted_citations, h + 1): break
        h += 1
        
    return h
    