from tkinter import *
import json
from tkinter import messagebox
# from main import *

RED = 'red'
WHITE = 'white'
FONT_A = ("Arial", 16, "normal")


def format_text(text, number):
    pass


class Homework:
    def __init__(self, subject: Label, description: Label, due_date: Label, status: Label, del_btn: Button):
        self.subject = subject
        self.description = description
        self.due_date = due_date
        self.status = status
        self.del_btn = del_btn
    
    def hide(self, user: str) -> None:
        delete = messagebox.askokcancel(title="Confirm", message="This homework will be deleted.\nAre you sure?")
        if delete:
            sub = self.subject.cget('text')
            des = self.description.cget('text')
            due = self.due_date.cget('text')
            print(sub, des, due)
            
            with open("data.json") as read_file:
                data = json.load(read_file)
                user_hw: dict = data[user]['homework']
            
            new_dict = {}
            for key, value in user_hw.items():
                if key != sub and value['description'] != des and value['due'] != due:
                    new_dict[key] = value
            
            user_hw = new_dict
            data[user]['homework'] = new_dict
            with open('data.json', mode='w') as write_file:
                json.dump(data, write_file, indent=4)
            
            self.subject.destroy()
            self.description.destroy()
            self.due_date.destroy()
            self.status.destroy()
            self.del_btn.destroy()


class HomeworkDisplay:
    def __init__(self, row, column, hw, subject):
        self.frame = Frame(assignments_tab)
        self.frame.configure(height=50, width=800)
        self.frame.grid(row=row, column=column)
        
        self.status = Label(self.frame, text='Due', fg='red', font=FONT, bg=WHITE)
        self.status.grid(row=1, column=1)
        
        self.subject = Label(self.frame, text=f"{subject}", padx=10, font=FONT, bg=WHITE)
        self.subject.grid(row=1, column=2)
        
        self.description = Label(self.frame, text=f"{hw[subject]['description']}", padx=20, font=FONT, bg=WHITE)
        self.description.grid(row=1, column=3)
        
        self.due = Label(self.frame, text=f"{hw[subject]['due_date']}", padx=10, font=FONT, bg=WHITE)
        self.due.grid(row=1, column=4)
        
        self.delete_btn = Button(self.frame, text="delete")
        self.delete_btn.configure(image=bin_image, bg=WHITE, borderwidth=0, highlightthickness=0, command=self.hide_and_delete)
        self.delete_btn.grid(row=1, column=5)
    
    def hide_and_delete(self):
        self.frame.destroy()
        pass
