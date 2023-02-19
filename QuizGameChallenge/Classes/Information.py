# importing random to randomly pickup the questions
# importing time to create timer
# importing threading for running the timer simultaneously
import random
from time import sleep
import threading
from tkinter import *

# defining Question Class


class Question:
    def __init__(self, question, options, right_answer, diff_lvl, base_point):
        self.question = question  # string
        self.options = options  # list of options (string)
        self.right_answer = right_answer  # string
        self.diff_lvl = diff_lvl  # integer
        self.base_point = base_point  # integer

    def get_answer(self, frame):
        global timeup
        timeup = False

        def enable():  # to enable next button when radiobutton is clicked
            next_button["state"] = NORMAL

        def assign():  # to assign the remaining time and chosen answer
            if int(timer_label["text"]) == 0:
                return 0, 0
            else:
                return key_options[v.get()], int(timer_label["text"])

        def done():  # to continue the function when then the user clicks next
            global timeup
            timeup = True

        def count_down():  # the timer function
            global timeup
            while timer_label["text"] != '0' and timeup == False:
                timer_label["text"] = str(int(timer_label["text"]) - 1)
                sleep(1)
            timeup = True

        v = IntVar()
        v.set(-1)
        question_label = Label(
            frame, text="\n" + self.question + "\n", wraplength=250, font="20")
        timer_label = Label(frame, text="60", font="Verdana 80")
        random.shuffle(self.options)  # to shuffle the options
        key_options = {i: self.options[i] for i in range(
            len(self.options))}  # to provide key to each option
        option_widgets = [Radiobutton(frame, text=value, variable=v, value=key,
                                      font="15", command=enable) for key, value in key_options.items()]
        next_button = Button(frame, text="NEXT", state=DISABLED,
                             width=20, activebackground="blue", command=done)
        timer_label.pack()
        question_label.pack()
        [option_widgets[i].pack(anchor=W) for i in range(len(option_widgets))]
        next_button.pack()
        cd_thread = threading.Thread(target=count_down)
        cd_thread.start()  # started countdown as thread
        while timeup == False:  # waiting for the user to give answer or time to finish
            frame.update()
        answer, rem_time = assign()
        return answer, rem_time

    def check_answer(self, answer):  # method to check the right answer
        if answer == self.right_answer:
            return True
        return False

# defining Admin Class


class Admin:
    def __init__(self, root):
        self.root = root  # main window
        self.check = True  # to keep waiting until the whole process of adding a question is done

    def __get_correct_answer(self, options, f, ADQ):
        def submit_func():  # when admin has chosen the correct answer
            f.write(var.get() + "\n")
            for widget in ADQ.winfo_children():
                widget.destroy()
            self.check = False  # ending the process
        var = StringVar()
        var.set(options[0])
        label1 = Label(ADQ, text="Choose the correct option:",
                       fg="blue", font="100")
        # creating options menu to choose the correct answer among the given options
        menu = OptionMenu(ADQ, var, *options)
        submit = Button(ADQ, text="Submit",
                        command=submit_func, width=10, height=2)
        label1.grid(row=0, column=0, pady=10)
        menu.grid(row=1, column=0, pady=10)
        submit.grid(row=2, column=0, pady=10)
        while self.check:  # waiting
            ADQ.update()

    def __add_options(self, f, ADQ):
        options = []  # to store the options given
        global i
        i = 1

        def write_option():  # to write the option in the file
            B1["state"] = DISABLED
            options.append(option.get())
            f.write(option.get() + "||")
            option.delete(0, 'end')
            global i
            i += 1
            label1["text"] = "Option " + str(i)

        def enableDisable(*args):  # to enable add button when text is written in Entry
            B1["state"] = NORMAL

        def done():  # when admin has given all the options
            for widget in ADQ.winfo_children():
                widget.destroy()
            f.write("\n")
            # calling get_correct_answer method
            self.__get_correct_answer(options, f, ADQ)

        label1 = Label(ADQ, text="Option 1", fg="blue", font="100")
        option = Entry(ADQ, width=25)
        B1 = Button(ADQ, text="Add", state=DISABLED, command=write_option)
        B2 = Button(ADQ, text="Done", command=done)
        option.bind("<Key>", enableDisable)
        label1.grid(row=0, column=0, columnspan=2, pady=20)
        option.grid(row=1, column=0, columnspan=2)
        B1.grid(row=2, column=0, padx=20, pady=20)
        B2.grid(row=2, column=1, padx=20, pady=20)
        while self.check:  # waiting
            ADQ.update()

    def add_question(self, f, ADQ):  # method to add the question
        def write_question():  # to write the question in the required file
            f.write(question.get() + "\n")
            for widget in ADQ.winfo_children():
                widget.destroy()
            self.__add_options(f, ADQ)  # calling add_options function

        def enableDisable(*args):  # to enable next button when text is written in Entry
            B1["state"] = NORMAL
        label1 = Label(ADQ, text="Enter the question: ", fg="blue", font="100")
        question = Entry(ADQ, width=50)
        question.bind("<Key>", enableDisable)
        label1.grid(row=0, column=0, columnspan=2)
        question.grid(row=1, column=0, columnspan=2, pady=10)
        B1 = Button(ADQ, text="Next", state=DISABLED, command=write_question)
        B1.grid(row=2, column=0, columnspan=2, padx=20, pady=20)
        while self.check:  # waiting
            ADQ.update()
        self.check = True

    def __getAllQuestions(self, filename):  # to get all the questions from the file
        file_location = ".\\Questions\\" + filename
        f = open(file_location, "r")
        li = [i for i in f.read().split("**||**") if i]
        li.pop()
        f.close()
        return li

    def __build_question_objects(self, li):
        return_list = []
        # li is the list of randomly picked information regarding question as a string
        for el in li:
            # splitting the lines
            question_att = [i for i in el.splitlines() if i]
            quest = question_att[0]  # first line is the question
            # second line is options separated by ||
            options = question_att[1].split("||")
            options.pop()  # removing the last ||
            right_answer = question_att[2]  # third line is the correct answer
            # fourth line is difficulty level and base points separated by a space
            diff_lvl, base_points = tuple(map(int, question_att[3].split()))
            question = Question(quest, options, right_answer,
                                diff_lvl, base_points)
            return_list.append(question)
        return return_list

    def load_questions(self):
        n = 10  # number of questions to be asked
        # randomly picking certain number of questions from each file
        easy_questions = random.sample(
            self.__getAllQuestions("Question_easy.txt"), n)
        medium_questions = random.sample(
            self.__getAllQuestions("Question_medium.txt"), n//2)
        hard_questions = random.sample(
            self.__getAllQuestions("Question_hard.txt"), n//2)
        HOT_questions = random.sample(
            self.__getAllQuestions("Question_HOT.txt"), n - 3)
        # building question objects
        easy_questions = self.__build_question_objects(easy_questions)
        medium_questions = self.__build_question_objects(medium_questions)
        hard_questions = self.__build_question_objects(hard_questions)
        HOT_questions = self.__build_question_objects(HOT_questions)

        # making list of the list of question objects
        questions = [easy_questions, medium_questions,
                     hard_questions, HOT_questions]

        return questions
