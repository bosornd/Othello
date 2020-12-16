from bangtal import *
from config import *
from board import *

class Stone(Object):
    def __init__(self, othello, ix, iy, shown = True):
        super().__init__(Config.IMAGE_STONE_BLANK)

        self.locate(othello, Config.BOARD_INIT_X + Config.STONE_SIZE_X * ix, Config.BOARD_INIT_Y + Config.STONE_SIZE_Y * iy)
        if shown: self.show()

        self.othello = othello
        self.ix = ix
        self.iy = iy

    def onMouseAction(self, x, y, action):
        self.othello.onClick(self.ix, self.iy)

    def setState(self, turn, state):
        if state == State.BLACK: self.setImage(Config.IMAGE_STONE_BLACK)
        elif state == State.WHITE: self.setImage(Config.IMAGE_STONE_WHITE)
        elif state == State.POSSIBLE: self.setImage(Config.IMAGE_STONE_BLACK_POSSIBLE if turn == Turn.BLACK else Config.IMAGE_STONE_WHITE_POSSIBLE)
        else: self.setImage(Config.IMAGE_STONE_BLANK)