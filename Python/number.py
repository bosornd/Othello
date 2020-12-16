from bangtal import *
from config import *

class Number(Object):
    def __init__(self, scene, x, y, shown = True):
        super().__init__(Config.IMAGE_PATH + "0.png")

        self.locate(scene, x, y)
        if shown: self.show()

    def setNumber(self, n):
        if n < 0 or n > 9: self.hide()
        else:
            self.setImage(Config.IMAGE_PATH + str(n) + ".png")
            self.show()