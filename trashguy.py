
from time import sleep
from sys import argv


class TrashGuy:
    def __init__(self, user_input, speed=1):
        self.user_input = user_input
        self.speed = 0.1 / speed
        self.trash = "🗑"
        self.right = "(> ^_^)>"
        self.left = "<(^_^ <)"
        self.l_space = " "
        self.r_space = " "
        self.user = self.right

    def print(self):
        print(f"{self.trash}{self.l_space}{self.user}{self.r_space}{self.user_input}", end="\r")
        sleep(self.speed)

    def go_right(self):
        self.print()
        while self.r_space:
            self.r_space = self.r_space[1:]
            self.l_space += " "
            self.print()

    def go_left(self):
        self.print()
        while self.l_space:
            self.l_space = self.l_space[1:]
            self.r_space += " "
            self.print()

    def take_letter(self):
        self.letter = self.user_input[0]
        self.user = self.letter + self.left
        self.user_input = self.user_input[1:]
        self.r_space += " "
        self.l_space = self.l_space[1:]

    def trash_letter(self):
        self.user = self.user[1:]
        self.r_space += " "
        self.print()
        self.user = self.right
        self.print()
        self.l_space += " "
        self.r_space = self.r_space[1:]

    def play(self):
        for _ in self.user_input:
            self.go_right()
            self.take_letter()
            self.go_left()
            self.trash_letter()


if __name__ == "__main__":
    if len(argv) == 2:
        TrashGuy(argv[1]).play()
    elif len(argv) == 3:
        if argv[2].isnumeric():
            TrashGuy(argv[1], int(argv[2])).play()
        else:
            print("Second argument must be speed (Default=1)")
    else:
        print(f"Syntax:\npython {argv[0]} [WORD]<str> <[SPEED]<int>")
