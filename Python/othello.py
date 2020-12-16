from bangtal import *
from config import *
from board import *

from stone import *
from number import *

class Othello(Scene):
    def __init__(self, name):
        super().__init__(name, Config.IMAGE_BACKGROUND)

        self.board = Board()
        self.stones = [[Stone(self, x, y) for x in range(self.board.width)]  for y in range(self.board.height)]

        self.numbers = [Number(self, Config.NUMBER11_X, Config.NUMBER_Y),
                        Number(self, Config.NUMBER12_X, Config.NUMBER_Y),
                        Number(self, Config.NUMBER21_X, Config.NUMBER_Y),
                        Number(self, Config.NUMBER22_X, Config.NUMBER_Y)]

        self.turn = Object(Config.IMAGE_TURN_BLACK)
        self.turn.locate(self, Config.TURN_X, Config.TURN_Y)
        self.turn.show()

        self.timer = Timer(Config.TIMER_TURN)
        self.timer.onTimeout = lambda : self.giveTurn()

    def giveTurn(self):
        if self.board.turn == Turn.BLACK:
            self.blackPlayer.onTurn()
        else:
            self.whitePlayer.onTurn()

    def onEnter(self):
        self.board.init()
        self.update()

    def onLeave(self):
        self.timer.stop()


    def putStone(self, x, y):
        if self.board.putStone(x, y):
            self.update()
            return True

        return False

    def update(self):
        for y in range(self.board.height):
            for x in range(self.board.width):
                self.stones[y][x].setState(self.board.turn, self.board.state[y][x])

        black = self.board.black
        white = self.board.white
        self.numbers[0].setNumber(black // 10 if black // 10 > 0 else -1)
        self.numbers[1].setNumber(black % 10)
        self.numbers[2].setNumber(white // 10 if white // 10 > 0 else white)
        self.numbers[3].setNumber(white % 10 if white // 10 > 0 else -1)

        if self.board.end:
            self.turn.hide()
            showMessage("END GAME!!!")
        else:
            self.turn.setImage(Config.IMAGE_TURN_BLACK if self.board.turn == Turn.BLACK else Config.IMAGE_TURN_WHITE)

        self.timer.set(Config.TIMER_TURN)
        self.timer.start()

    def setPlayer(self, turn, player):
        if turn == Turn.BLACK: self.blackPlayer = player
        else: self.whitePlayer = player

    def onClick(self, x, y):
        if self.board.turn == Turn.BLACK:
            self.blackPlayer.onClick(x, y)
        else:
            self.whitePlayer.onClick(x, y)


