def solution(genres, plays):
    genres_hash = {}
    
    # 장르를 key 로 list 인 value 의 음악들을 넣어줍니다.
    # 단 이떄 value 의 0번째 인덱스는 장르의 플레이 수의 총 합입니다.
    for i, g in enumerate(genres):
        if genres_hash.get(g) == None:
            genres_hash[g] = [plays[i], ( i, g, plays[i] )]
        else:
            genres_hash[g][0] += plays[i]
            genres_hash[g].append(( i, g, plays[i] ))
    
    # 플레이 수 총 합으로 장르를 내림차순 정렬합니다.
    genres_and_plays = [(g[0], g[1][0]) for g in genres_hash.items()]
    sorted_genres_with_plays = sorted(genres_and_plays, key=lambda x: x[1], reverse=True)
    sorted_genres = [ g[0] for g in sorted_genres_with_plays ]
    
    # 각 장르별 2개 혹은 1개의 음악을 뽑아 앨범에 넣습니다.
    best_album = []
    for g in sorted_genres:
        # 장르별 음악을 플레이수로 내림차순 정렬합니다.
        # 이 때 해시 테이블의 value 0번째 인덱스는 플레이수이므로 슬라이스합니다.
        sorted_music = sorted(genres_hash[g][1:], key=lambda x: x[2], reverse=True)
        if len(sorted_music) >= 2:
            best_album.extend([m[0] for m in sorted_music][0:2])
        else:
            best_album.append(sorted_music[0][0])

    # "장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다."
    # 위 조건은 이미 노래가 고유번호 순서대로 추가되어 있으므로 따로 신경쓸 필요가 없습니다.
    
    return best_album