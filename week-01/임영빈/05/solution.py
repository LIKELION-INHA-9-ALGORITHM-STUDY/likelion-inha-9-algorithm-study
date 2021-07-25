def solution(genres, plays):
	music_num = len(genres)
	genres_count = dict()
	musics = list()
	answer = list()

	# music 리스트 만들기 후에 정렬
	# 저장 방식 => [(idx, genre, play), ...]
	for i in range(music_num):
		musics.append((i,genres[i],plays[i]))
	musics = sorted(musics, key=lambda item: item[2], reverse=True)

	# genre별로 count기록 후에 정렬
	# 저장 방식 => {“classic” : 1450, “pop”: 3100, ...}
	for i in range(music_num):
		genres_count[genres[i]] = genres_count.get(genres[i],0) + plays[i]
	genres_count = sorted(genres_count.items(), key=lambda item: item[1], reverse=True)

	# 바깥 for문 : 많이 재생된 장르순서로
	# 안쪽 for문 : 장르에 해당하는 idx answer에추가
	for (genre, c) in genres_count:
		count = 0
		for (music_idx, music_genre, music_c) in musics:
			if music_genre == genre:
				answer.append(music_idx)
				count = count + 1
			if count > 1:
				break
	return(answer)