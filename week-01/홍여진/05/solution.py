def solution(genres, plays):
    answer = []
    dict = {} #어떤 장르의 노래 고유번호, 노래 재생시간. ex) {'classic': [(500, 0), (150, 2), (800, 3)], 'pop': [(600, 1), (2500, 4)]}
    genres_playtime={} #장르별 총 재생시간 ex) {'classic': 1450, 'pop': 3100}

    for i in range(len(genres)):#dict, genres_playtime에 넣는 과정
        genres_playtime[genres[i]] = genres_playtime.get(genres[i],0)+plays[i]
        dict[genres[i]] = dict.get(genres[i],[])+[(plays[i],i)]

    genres_playtime = sorted(genres_playtime.items(), key=lambda x: x[1], reverse=True) #재생시간 높은 순으로 정렬

    for (g,gp) in genres_playtime:
        dict[g] = sorted(dict[g], key = lambda x : x[0], reverse=True) #장르별 재생시간이 높은 순부터 dict[g]를 찾아 노래 재생시간이 높은 순으로 정렬
        print(dict[g])
        for (p,i) in dict[g][:2]:#상위 두 번째곡까지 집어넣음
            answer += [i]
    return answer