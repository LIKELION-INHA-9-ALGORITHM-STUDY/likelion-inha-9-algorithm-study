def solution(phoneBook):
    phoneBook.sort()
    for i in range(0, len(phoneBook)-1):
        if phoneBook[i+1].startswith(phoneBook[i]):#정렬 후 어떤 원소 i의 바로 다음 원소가 i로 시작하면 접두사이므로 return false
            return False
    return True