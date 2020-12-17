from player import *
from board import *
from random import randint

class Computer2(Player):
    def __init__(self, othello):
        super().__init__(othello)

    def onTurn(self):
        board = self.othello.board

        max = 0
        weight = 5
        for y in range(board.height):
            for x in range(board.width):
                c = board.count[y][x]
                if c > 0:
                    if x == 0 or x == board.width - 1: c += weight
                    if y == 0 or y == board.height - 1: c += weight

                if c > max or (c == max and randint(0, 1) == 0):
                    max, tx, ty = c, x, y

        self.othello.putStone(tx, ty)
