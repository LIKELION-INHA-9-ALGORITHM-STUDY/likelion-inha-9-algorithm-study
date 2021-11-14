def solution(sizes):
    rotated_sizes = list(map(lambda t: [t[1], t[0]], sizes))
    
    lengths = set()
    for size in sizes:
        lengths.add(size[0])
        lengths.add(size[1])
        
    lengths = sorted(list(lengths))
    
    for length in lengths:
        o1 = [length >= size[0] for size in sizes]
        o2 = [length >= size[0] for size in rotated_sizes]
        o3 = [o1[i] or o2[i] for i in range(len(o1))]
        
        if all(o3):
            c1 = list(filter(lambda size: o1[sizes.index(size)], sizes))
            c2 = list(filter(lambda size: o2[rotated_sizes.index(size)], rotated_sizes))
            max_v_len = max([size[1] for size in c1 + c2 ])
            return max_v_len * length