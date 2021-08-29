def ud_distance(target_letter):
    alphabets = list(map(chr, range(65, 91)))
    target_index = alphabets.index(target_letter)

    to_left = len(alphabets) - target_index
    to_right = target_index

    return min([to_left, to_right])

def lr_distance(ud_list, cursor):
    if ud_list[cursor] > 0: return (0, cursor)

    left_cursor = right_cursor = cursor
    left_count = right_count = 0

    while True:
        left_cursor = left_cursor - 1 if left_cursor > 0 else len(ud_list) - 1
        left_count += 1

        if ud_list[left_cursor] == 0: continue  # do while 처럼 사용하기 위함
        break

    while True:
        right_cursor = (right_cursor + 1) % (len(ud_list))
        right_count += 1

        if ud_list[right_cursor] == 0: continue
        break

    if left_count < right_count: return (left_count, left_cursor)
    else: return (right_count, right_cursor)


def solution(name):
    move_count = 0
    cursor = 0

    ud_list = list(map(lambda c: ud_distance(c), name))

    while sum(ud_list) > 0:
        lr = lr_distance(ud_list, cursor)
        cursor = lr[1]

        move_count += lr[0]
        move_count += ud_distance(name[cursor])

        ud_list[cursor] = 0

    return move_count