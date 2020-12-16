from bangtal import *
from config import *
from othello import *

setGameOption(GameOption.ROOM_TITLE, False)
setGameOption(GameOption.INVENTORY_BUTTON, False)
setGameOption(GameOption.MESSAGE_BOX_BUTTON, False)

main = Scene("오델로 게임", Config.IMAGE_GAME)
othello = Othello("오델로 게임")

def createObject(image, scene, x, y, shown = True):
    o = Object(image)
    o.locate(scene, x, y)
    if shown: o.show()
    return o

def start_game(blackPlayer, whitePlayer):
    othello.setPlayer(Turn.BLACK, blackPlayer)
    othello.setPlayer(Turn.WHITE, whitePlayer)
    othello.enter()
    pass

from user import *
from computer import *

user1 = User(othello)
user2 = User(othello)
com1 = Computer(othello)
com2 = Computer(othello)

game1 = createObject(Config.IMAGE_GAME_1, main, 450, 200)
game1.onMouseAction = lambda x, y, action : start_game(user1, user2)

game2 = createObject(Config.IMAGE_GAME_2, main, 450, 120)
game2.onMouseAction = lambda x, y, action : start_game(user1, com1)

game3 = createObject(Config.IMAGE_GAME_3, main, 450, 40)
game3.onMouseAction = lambda x, y, action : start_game(com1, com2)

end = createObject(Config.IMAGE_GAME_END, othello, 1100, 20);
end.onMouseAction = lambda x, y, action: main.enter()

startGame(main)