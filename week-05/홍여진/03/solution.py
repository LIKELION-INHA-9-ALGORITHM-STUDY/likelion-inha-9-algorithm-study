def solution(number, k):
    count = 0  # 수를 제거할때마다 카운트

    # 단순하게? 뒤의 값보다 작으면 조진다
    idx = 0
    for i in range(len(number)):
        if idx == len(number) - 1:  # 맨 마지막 원소까지 검사했는데도 count를 못채웠을경우 count가 부족한 수만큼 뒤에서 자른다
            return number[:len(number)-(k-count)]
        idx += 1
        if number[idx-1] >= number[idx]:  # number[idx-1]가 바로 뒤의 값보다 클 경우 남겨둔다
            continue

        # number[idx]가 바로 뒤의 값보다 작을 경우 number[idx-1]부터 0번째 숫자까지 number[idx]와 비교하고, number[idx]가 더 클 경우 앞 숫자들을 날려버린다
        winner = number[idx]
        a = idx-1
        for j in range(a, -1, -1):
            print(j)
            if number[j] < winner:
                number = number[0:j]+number[j+1:]
                count += 1
                if count == k:
                    return number
                idx -= 1
            else:
                break
