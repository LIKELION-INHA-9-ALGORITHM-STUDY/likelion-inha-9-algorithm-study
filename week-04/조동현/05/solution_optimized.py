class Board:
    def __init__(self, size):
        self.size = size
        self.board = [[None] * size for _ in range(size)]

    def place_candy(self, x, y, color):
        self.board[y][x] = color

    def swap_right(self, x, y):
        if x + 1 >= self.size: return False
        self.board[y][x], self.board[y][x + 1] = self.board[y][x + 1], self.board[y][x]

    def swap_down(self, x, y):
        if y + 1 >= self.size: return False
        self.board[y][x], self.board[y + 1][x] = self.board[y + 1][x], self.board[y][x]

    def h_sequence(self, y):
        if y >= self.size: return 0

        counts = set()

        current_row = self.board[y]
        current = current_row[0]
        count = 0

        for x in range(self.size):
            pointer = current_row[x]

            if current != pointer:
                current = current_row[x]
                counts.add(count)
                count = 0

            count += 1

        counts.add(count)

        return max(counts)

    def v_sequence(self, x):
        if x >= self.size: return False

        counts = set()

        current = self.board[0][x]
        count = 0

        for y in range(self.size):
            pointer = self.board[y][x]

            if current != pointer:
                current = self.board[y][x]
                counts.add(count)
                count = 0
            count += 1

        counts.add(count)

        return max(counts)

    def search(self):
        arr = []
        for y in range(self.size):
            for x in range(self.size):
                self.swap_right(x, y)
                arr.append(self.h_sequence(y))
                arr.append(self.v_sequence(x))
                arr.append(self.v_sequence(x + 1))
                self.swap_right(x, y)

                self.swap_down(x, y)
                arr.append(self.h_sequence(y))
                arr.append(self.h_sequence(y+1))
                arr.append(self.v_sequence(x))
                self.swap_down(x, y)

        return max(arr)

if __name__ == "__main__":
    size = int(input())
    b = Board(size)

    for y in range(size):
        row = input()

        for x, col in enumerate(row):
            b.place_candy(x, y, col)

    print(b.search())