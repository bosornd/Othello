from player import *

class User(Player):
    def __init__(self, othello):
        super().__init__(othello)
        self.turn = False

    def onTurn(self):
        self.turn = True

    def onClick(self, x, y):
        if self.turn:
            if self.othello.putStone(x, y):
                self.turn = False
