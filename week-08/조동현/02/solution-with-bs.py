n = int(input())
n_list = sorted(map(int, input().split(" ")))

m = int(input())
m_list = list(map(int, input().split(" ")))

def binary_search(data, target, low, high):
    if low > high:
        return 0

    middle_idx = (low + high) // 2
    middle = data[middle_idx]

    if middle == target:
        left = right = middle_idx

        while left > 0:
            if data[left - 1] != target: break
            left -= 1

        while right < len(data) - 1:
            if data[right + 1] != target: break
            right += 1

        return right - left + 1
    elif middle > target:
        return binary_search(data, target, low, middle_idx - 1)
    elif middle < target:
        return binary_search(data, target, middle_idx + 1, high)

# 이미 계산한 값에 대해 해시에 저장하지 않으면 시간 초과 발생
# m_list 에 중복된 숫자가 들어간 테스트케이스가 있는 것 같다.
hash = {}
for check in m_list:
    if check not in hash:
        hash[check] = binary_search(n_list, check, 0, len(n_list) - 1)

for check in m_list:
    if check not in hash:
        print(0, end=" ")
    else:
        print(hash[check], end=" ")