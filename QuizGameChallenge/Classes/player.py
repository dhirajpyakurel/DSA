# importing Question from another python file in same directory
# importing tkinter
from Classes.Information import Question
from tkinter import *

# defining Player Class


class Player:
    def __init__(self, name, regno):
        self.name = name
        self.regno = regno
        self.score = 0

    def add_score(self, base_points, rem_time, diff_lvl):
        points = base_points + (rem_time*diff_lvl/60)
        self.score += round(points, 3)

# defining Game Class to handle the main quiz game


class Game:
    def __init__(self, root):
        self.root = root

    def launch_game(self, stacks, q_no, diff_lvl, player, number_of_questions):
        if q_no > number_of_questions:
            return
        frame = LabelFrame(self.root, text="Question " +
                           str(q_no), padx=250, pady=20)
        frame.place(x=700, y=250)
        # stacks is list containing question objects
        stack = stacks[diff_lvl-1]
        question = stack.pop()
        answer, rem_time = question.get_answer(frame)
        frame.destroy()
        if question.check_answer(answer) and rem_time != 0:
            player.add_score(question.base_point, rem_time, diff_lvl)
            if diff_lvl < 4:
                diff_lvl += 1
        else:
            if diff_lvl > 1:
                diff_lvl -= 1
        self.launch_game(stacks, q_no+1, diff_lvl, player, number_of_questions)
