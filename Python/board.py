from enum import Enum

class Turn(Enum):
    BLACK       = 1
    WHITE       = 2

class State(Enum):
    BLACK       = 1
    WHITE       = 2
    POSSIBLE    = 3
    NONE        = 0

class Board:
    width       = 8
    height      = 8

    def __init__(self):
        pass

    def init(self):
        self.state = [[State.NONE for _ in range(self.width)] for _ in range(self.height)]
        self.count = [[0 for _ in range(self.width)] for _ in range(self.height)]

        self.state[3][3] = State.BLACK
        self.state[3][4] = State.WHITE
        self.state[4][3] = State.WHITE
        self.state[4][4] = State.BLACK

        self.turn = Turn.WHITE
        self.black = 0
        self.white = 0
        self.end = False

        self.nextTurn()

    def nextTurn(self):
        self.turn = Turn.BLACK if self.turn == Turn.WHITE else Turn.WHITE

        self.black = 0
        self.white = 0
        for y in range(self.height):
            for x in range(self.width):
                if self.state[y][x] == State.BLACK: self.black += 1
                elif self.state[y][x] == State.WHITE: self.white += 1

        possible = False
        for y in range(self.height):
            for x in range(self.width):
                self.count[y][x] = self.reverse(x, y, False)
                if self.count[y][x] > 0:
                    self.state[y][x] = State.POSSIBLE
                    possible = True

        return possible

    def reverse(self, x, y, execute = True):
        if self.state[y][x] == State.BLACK or self.state[y][x] == State.WHITE:
            return 0

        self.state[y][x] = State.NONE if execute != True else (State.BLACK if self.turn == Turn.BLACK else State.WHITE)

        delta = ((0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1))

        count = 0
        for d in delta:
            count += self.reverseDiagonal(x, y, d[0], d[1], execute)

        return count

    def reverseDiagonal(self, x, y, dx, dy, execute = True):
        if self.turn == Turn.BLACK:
            mine = State.BLACK
            other = State.WHITE
        else:
            mine = State.WHITE
            other = State.BLACK

        count = 0
        while True:
            x += dx
            y += dy

            if x < 0 or x >= self.width or y < 0 or y >= self.height:
                break

            if self.state[y][x] == other:
                count += 1
            elif self.state[y][x] == mine:
                if execute:
                    while True:
                        x -= dx
                        y -= dy
                        if x < 0 or x >= self.width or y < 0 or y >= self.height:
                            break

                        if self.state[y][x] == other:
                            self.state[y][x] = mine
                        else:
                            break
                return count
            else:
                break
        return 0

    def putStone(self, x, y):
        if self.state[y][x] == State.POSSIBLE:
            self.reverse(x, y)

            if self.nextTurn() == False:
                if self.nextTurn() == False:
                    self.end = True

            return True

        return False