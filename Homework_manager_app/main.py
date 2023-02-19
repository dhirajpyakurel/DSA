import json
from tkinter import *
from tkinter import messagebox
from tkinter import ttk
from tkcalendar import Calendar
from todo import Todo
from cipher import encode, decode
from sort import sort_hw
# from delete import delete_hw
from formatted_img import *

# ------------------------------- CONSTANTS ----------------------------------- #

FONT = ("Arial", 17, 'normal')
FONT_B = ("Arial", 26, "bold")
FONT_LOGIN = ('Noto Sans Canadian Aboriginal', 25, 'bold')
DUE_HW_COUNTER = 0
PASSWORD_LEN = 2
WHITE = 'white'
GREEN = 'green'
BLACK = 'black'
BLUE = "#57a1f8"
RED = '#FEDEFF'
LIGHT_GREEN = '#a6ff4d'
LIGHT_YELLOW = '#ffff66'
note_row = 1
note_column = 0

USERNAME = 'ram'  # TODO remove this line and use above line
LOGGED_IN = True  # TODO remove this line and use above line

LOGGED_IN = False
USERNAME: str = 'ram'

# --------------------------------- LOGIN MANAGEMENT ------------------------------------#

word_list = []


def get_label_text(frame):
    label_text = []
    for widget in frame.grid_slaves():
        if isinstance(widget, Label) or isinstance(widget, Button):
            text = widget.cget("text").strip(' ').lower()
            text = text.split()
            label_text.extend(text)
    return label_text


def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if str(arr[j]) < str(arr[min_idx]):
                min_idx = j
        (arr[i], arr[min_idx]) = (arr[min_idx], arr[i])
    return arr


def set_username_globally(var: str):
    global USERNAME
    USERNAME = var


def quit_app(event):
    window.destroy()


def l_u_on_enter(event):
    l_username_entry.delete(0, END)


def l_u_on_leave(event):
    name = l_username_entry.get()
    if name == '':
        l_username_entry.insert(0, 'username')


def s_u_on_enter(event):
    s_username_entry.delete(0, END)


def s_u_on_leave(event):
    name = s_username_entry.get()
    if name == '':
        s_username_entry.insert(0, 'username')


def s_p_on_enter(event):
    s_password_entry.delete(0, END)


def l_p_on_enter(event):
    l_password_entry.delete(0, END)


def go_back():
    # global about_frame
    about_frame.destroy()


def show_about():
    global about_frame, main_window
    about_frame = Frame(main_window, width=500, height=500, bg=WHITE)
    about_frame.place(x=440, y=0)
    
    Button(about_frame, text="Back", bd=0, fg=WHITE, bg="light green", cursor='hand2', pady=10, padx=15,
           font=("Arial", 14, "bold"), highlightthickness=0, command=go_back).place(y=20, x=385)
    
    Label(about_frame, text="Creators", font=("Courier", 20, "bold"), fg=BLACK, bg=WHITE).place(x=200, y=90)
    Label(about_frame, text=' S Sonim\n M Aashiq Kumar\n A Rammani\n M Mandeep', fg=BLACK, bg=WHITE,
          justify=LEFT).place(x=180, y=130)
    pass


def signup(username_, password_, confirm_password_):
    global USERNAME, complete_data, current_user_data
    password = password_.get()
    username = username_.get()
    confirm_password = confirm_password_.get()
    
    try:
        # ----------------- check validity of username and password ---------------#
        
        with open("login.json") as login_file:
            login_data = json.load(login_file)
        # print(type(login_data))
        users = []
        for user in login_data.keys():
            users.append((decode(user)))
            
        if username in users:
            messagebox.showerror(title='Username Error!',
                                 message='This username has been taken. Please chose another one.')
        
        elif len(password) < PASSWORD_LEN:
            messagebox.showerror(title='Too short password!',
                                 message=f'Password must be at least {PASSWORD_LEN} characters')
        
        elif password != confirm_password:
            messagebox.showerror(title='Password did not Match',
                                 message='confirmation of new password failed, Enter same password at both fields ')
        
        else:
            # it is valid
            
            set_username_globally(username)
            messagebox.showinfo(title='Success',
                                message=f"""Your account has been created
                                \n username:{username}
                                \npassword: {password}""")
            
            new_user = {
                encode(f"{username}"): {
                    "password": encode(f"{password}")
                }
            }
            login_data.update(new_user)
            
            with open('login.json', mode='w') as write_file:
                json.dump(login_data, write_file, indent=4)
            try:
                with open('data.json') as read_file:
                    complete_data = json.load(read_file)
                
                current_user_data = {
                    decode(f"{USERNAME}"): {
                        "homework": {},
                        "todo": {},
                        "notes": {},
                        "completed_hw": {}
                    }
                }
                complete_data.update(current_user_data)
                with open('data.json', mode='w') as write_file:
                    json.dump(complete_data, write_file, indent=4)
            except FileNotFoundError:
                messagebox.showerror(
                    title='FileNotFoundError!',
                    message='data.json file seems to be empty.\n To solve the issue, add a set of curly braces ie {} '
                            'inside data.json file')
    
    except FileNotFoundError:
        """Below code is for THE VERY FIRST sign up"""
        
        if len(password) < PASSWORD_LEN:
            messagebox.showerror(title='Too short password!',
                                 message=f'Password must be at least {PASSWORD_LEN} characters')
        
        elif password != confirm_password:
            messagebox.showerror(title='Password did not Match',
                                 message='confirmation of new password failed, Enter same password at both fields ')
        
        else:
            set_username_globally(username)
            new_user = {
                encode(f"{username}"): {
                    'password': encode(f"{password}")
                }
            }
            with open("login.json", mode='w') as write_file:
                json.dump(new_user, write_file, indent=4)
            messagebox.showinfo(title='Success',
                                message=f"""Your account has been created
                                            \n username:{USERNAME}
                                            \npassword: {password}""")
            signup_frame.destroy()


def signup_screen():
    global signup_frame, s_username_entry, s_password_entry, main_window
    
    xc = 100
    yc = 100
    
    signup_frame = Frame(main_window, width=500, height=500, bg=WHITE)
    signup_frame.place(x=480, y=0)
    
    s_username = StringVar(signup_frame)
    s_password = StringVar(signup_frame)
    confirm_password = StringVar(signup_frame)
    
    heading = Label(signup_frame, text="SIGN UP", font=FONT_LOGIN, bg='white')
    heading.place(x=xc + 50, y=yc - 30)
    
    Label(signup_frame, text='Username', font=FONT, bg='white').place(x=xc + 68, y=yc + 50)
    s_username_entry = Entry(signup_frame, width=25, fg='black', border=0, bg="white",
                             font=('Noto Sans Myanmar UI', 11), textvariable=s_username)
    s_username_entry.place(x=xc, y=yc + 90)
    s_username_entry.focus()
    
    s_username_entry.insert(0, 'username')
    s_username_entry.bind('<FocusIn>', s_u_on_enter)
    s_username_entry.bind('<FocusOut>', s_u_on_leave)
    #
    Label(signup_frame, text='Password', font=FONT, bg='white').place(x=xc + 70, y=yc + 130)
    
    s_password_entry = Entry(signup_frame, width=25, fg='black', border=0, bg='white',
                             font=('Noto Sans Myanmar UI', 11), textvariable=s_password, show='*')
    s_password_entry.bind('<FocusIn>', s_p_on_enter)
    s_password_entry.place(x=100, y=yc + 170)
    
    Label(signup_frame, font=FONT, text='confirm password', bg='white').place(x=xc + 28, y=yc + 210)
    confirm_password_entry = Entry(signup_frame, width=25, fg='black', border=0, bg='white',
                                   font=('Noto Sans Myanmar UI', 11), textvariable=confirm_password, show='*')
    confirm_password_entry.place(x=xc, y=yc + 260)
    
    # Store the image object in a global variable, so it is not garbage collected by python's memory manager
    signup_btn_img = signup_btn_image()
    global signup_btn_img2
    signup_btn_img2 = signup_btn_img
    
    signup_button = Button(signup_frame, image=signup_btn_img2, font=FONT,
                           command=lambda: signup(s_username, s_password, confirm_password),
                           pady=7,
                           bg='#57a1f8',
                           fg='white',
                           border=0,
                           cursor='hand2')
    signup_button.place(x=xc + 70, y=yc + 310)
    
    Button(signup_frame, text="Back", bd=0, fg=WHITE, bg=LIGHT_GREEN, cursor="hand2", font=FONT, highlightthickness=0,
           command=signup_frame.destroy).place(x=350, y=20)


def login(username, password):
    global LOGGED_IN, USERNAME, main_window
    
    try:
        with open("login.json") as read_login_file:
            login_data = json.load(read_login_file)
    except FileNotFoundError:
        messagebox.showinfo(title='Sign Up first!', message="Register by creating an account below")
    else:
        for user in login_data:
            if username.get() == decode(f"{user}") and password.get() == decode(login_data[user]['password']):
                print(decode(f"{user}"))
                print(decode(f"{login_data[user]['password']}"))
                LOGGED_IN = True
                USERNAME = username.get()
                main_window.destroy()
                return
        messagebox.showerror(title='Error', message=f'Invalid Username {username.get()} or Password {password.get()}! Try Again.')
        main_window.destroy()
        login_screen()


def login_screen():
    global l_username_entry, l_password_entry, main_window
    
    xc = 100
    yc = 100
    
    main_window = Tk()
    main_window.title('Homework Aid main window')
    main_window.configure(bg=WHITE)
    main_window.geometry('925x500+300+200')
    main_window.resizable(False, False)
    
    login_img = PhotoImage(file='login_img.png')
    Label(main_window, image=login_img, bg='white').place(x=50, y=50)
    
    login_frame = Frame(main_window, width=500, height=500, bg=WHITE)
    login_frame.place(x=480, y=0)
    
    heading = Label(login_frame, text="SIGN IN ", font=FONT_LOGIN, bg='white')
    heading.place(x=xc + 50, y=yc - 30)
    
    l_username = StringVar(main_window)
    l_password = StringVar(main_window)
    
    Label(login_frame, text='Username', font=FONT, bg='white').place(x=xc + 65, y=yc + 50)
    l_username_entry = Entry(login_frame, width=25, fg='black', border=0, bg="white", font=('Noto Sans Myanmar UI', 11),
                             textvariable=l_username)
    l_username_entry.focus()
    l_username_entry.place(x=xc, y=yc + 80 + 10)
    l_username_entry.insert(0, 'username')
    l_username_entry.bind('<FocusIn>', l_u_on_enter)
    l_username_entry.bind('<FocusOut>', l_u_on_leave)
    
    password_label = Label(login_frame, text='Password', font=FONT, bg='white')
    password_label.place(x=170, y=yc + 120 + 10)
    
    l_password_entry = Entry(login_frame, width=25, fg='black', border=0, bg='white', font=('Noto Sans Myanmar UI', 11),
                             textvariable=l_password, show='*')
    l_password_entry.bind('<FocusIn>', l_p_on_enter)
    l_password_entry.place(x=100, y=yc + 160 + 10)
    
    login_btn_img = login_bth_image()
    login_button = Button(login_frame, pady=7, image=login_btn_img, bg=WHITE, fg='white', border=0, borderwidth=0,
                          highlightthickness=0, highlightcolor=WHITE,
                          cursor='hand1',
                          command=lambda: login(l_username, l_password))
    login_button.place(x=170, y=yc + 200 + 10)
    
    Label(login_frame, text="Do not have an account?", fg='black', bg='white', font=('Noto Sans Myanmar UI', 15)).place(
        x=122,
        y=yc + 285)
    signup_btn_img = signup_btn_image()
    Button(login_frame, image=signup_btn_img, border=0, borderwidth=0, highlightthickness=0, highlightcolor=WHITE,
           bg=WHITE, cursor='hand1', fg='#57a1f8',
           command=signup_screen).place(
        x=172, y=yc + 335)
    
    Button(login_frame, text="About", bd=0, fg=WHITE, bg="light green", cursor='hand2', font=("Arial", 14, "bold"),
           highlightthickness=0, command=show_about, padx=10, pady=10).place(y=20, x=350)
    main_window.mainloop()


# ----------------------------- CREATE FIVE TABS ------------------------------ #


def create_six_tabs(nb):
    tab1 = ttk.Frame(nb)
    tab2 = ttk.Frame(nb)
    tab3 = ttk.Frame(nb)
    tab4 = ttk.Frame(nb)
    tab5 = ttk.Frame(nb)
    tab6 = ttk.Frame(nb)
    tab_style = ttk.Style()
    tab_style.configure('TNotebook.Tab',
                        font=('Arial', 16, 'bold'),
                        foreground=WHITE,
                        background=BLUE,
                        width=15,
                        padding=(5, 10, 5, 10))
    tab_style.configure("TFrame", background=WHITE, foreground=BLACK, width=900, height=900)
    
    nb.add(tab1, text="    Dashboard  ")
    nb.add(tab2, text="   Assignments ")
    nb.add(tab3, text="      Notes  ")
    nb.add(tab4, text="    Todo  ")
    nb.add(tab5, text="Add Assignments", state='hidden')
    nb.add(tab6, text="New Todo", state='hidden')
    nb.pack(fill="both", expand=True)
    nb.enable_traversal()
    
    return tab1, tab2, tab3, tab4, tab5, tab6


# ---------------------------- BACKEND?? --------------------------------- #


def insert_to_due_entry(date_picked):
    calendar.destroy()
    confirm_date_button.destroy()
    date = date_picked.get()
    hw_due_entry.delete('0', END)
    hw_due_entry.insert('0', date)


def pick_due_date():
    global calendar, confirm_date_button
    hw_due_entry.configure(state='normal')
    date_picked = StringVar(add_hw_tab, Calendar.date.today().strftime("%y/%m/%d"))
    calendar = Calendar(
        add_hw_tab,
        date_pattern="yyyy/mm/dd",
        textvariable=date_picked,
        showweeknumbers=False,
        showothermonthdays=False
    )
    confirm_date_button = Button(add_hw_tab, text='Confirm date', cursor='hand1',
                                 command=lambda: insert_to_due_entry(date_picked))
    confirm_date_button.grid(row=6, column=3)
    calendar.grid(row=5, column=3)


def add_hw_button(tab_hw):
    global hw_due_entry, pick_date_button, hw_subject_entry, hw_content_entry
    
    # un-hide the hidden tab (tab number 4 is "Add Hw Tab")
    notebook.tab(add_hw_tab, state='normal')
    notebook.select(add_hw_tab)
    
    # 1st row
    Label(tab_hw, text="Enter Subject", font=FONT, pady=10, padx=20).grid(row=1, column=1)
    hw_subject_entry = Entry(tab_hw, width=40, font=FONT)
    hw_subject_entry.focus()
    hw_subject_entry.grid(row=1, column=2)
    
    # 2nd row
    Label(tab_hw, text="Enter Description", font=FONT, pady=10, padx=20).grid(row=2, column=1)
    hw_content_entry = Entry(tab_hw, width=40, font=FONT)
    hw_content_entry.grid(row=2, column=2)
    
    # 3rd row
    Label(tab_hw, text="Enter Due date", font=FONT, pady=10, padx=20).grid(row=3, column=1)
    hw_due_entry = Entry(tab_hw, width=40, font=FONT, state='readonly', readonlybackground=WHITE)
    hw_due_entry.grid(row=3, column=2)
    
    # the calendar emoji  🗓 doses not display correctly
    pick_date_button = Button(tab_hw, text="📅Pick a date 🗓️", cursor='hand2', bg=WHITE, command=pick_due_date)
    pick_date_button.grid(row=4, column=2)
    
    # save button
    Button(tab_hw, text="Save Homework",bg=WHITE, font=FONT, command=save_hw, cursor='hand1').grid(row=5, column=2)


def show_headers():
    create_hw_btn = Button(assignments_tab,
                           text="Create homework",
                           cursor='hand1',
                           border=0, pady=7, borderwidth=0,
                           fg=WHITE, bg=BLUE,
                           font=FONT, command=lambda: add_hw_button(add_hw_tab)
                           )
    create_hw_btn.grid(row=0, column=2)
    Label(assignments_tab, text="", font=FONT, fg=BLUE, bg=WHITE).grid(row=1, column=0, columnspan=4)
    Label(assignments_tab, text="Due Homeworks", font=("Arial", 26, "bold"), padx=10, fg="#7286D3", bg=WHITE).grid(
        row=0, column=0, columnspan=2)
    Label(assignments_tab, text=" Status ", padx=5, font=("Arial", 16, "bold"), bg=BLUE, fg=WHITE).grid(row=2,
                                                                                                        column=0)
    Label(assignments_tab, text="Subjects", padx=10, font=("Arial", 16, "bold"), bg=BLUE, fg=WHITE).grid(row=2,
                                                                                                         column=1)
    Label(assignments_tab, text="Description", padx=20, font=("Arial", 16, "bold"), bg=BLUE, fg=WHITE).grid(row=2,
                                                                                                            column=2)
    Label(assignments_tab, text="Due Date", padx=10, font=("Arial", 16, "bold"), bg=BLUE, fg=WHITE).grid(row=2,
                                                                                                         column=3)
    ttk.Separator(assignments_tab, orient=HORIZONTAL).grid(row=3, column=0, columnspan=6, sticky='ew')


class HomeworkDisplay:
    
    def __init__(self, hw, subject, row, col):
        self.status = Label(assignments_tab, text='Due', fg='red', font=FONT, bg=WHITE)
        self.status.grid(row=row, column=col)
        
        self.subject = Label(assignments_tab, text=f"{subject}", wraplength=150, padx=10, font=FONT, bg=WHITE)
        self.subject.grid(row=row, column=col + 1)
        
        self.description = Label(assignments_tab, text=f"{hw[subject]['description']}", width=35, wraplength=400,
                                 padx=20, font=FONT, bg=RED)
        self.description.grid(row=row, column=col + 2)
        
        self.due = Label(assignments_tab, text=f"{hw[subject]['due_date']}", padx=10, font=FONT, bg=WHITE)
        self.due.grid(row=row, column=col + 3)
        
        if hw[subject]['completed'] is True:
            self.status.configure(text="Completed", fg=GREEN)
        
        self.delete_btn = Button(assignments_tab, text="delete")
        self.delete_btn.configure(image=bin_image, bg=WHITE, borderwidth=0, highlightthickness=0, command=self.hide)
        self.delete_btn.grid(row=row, column=col + 4)
        
        self.separator = ttk.Separator(assignments_tab, orient=HORIZONTAL)
        self.separator.grid(row=row + 1, column=0, columnspan=6, sticky='ew')
    
    def hide(self):
        self.status.destroy()
        self.subject.destroy()
        self.delete_btn.destroy()
        self.description.destroy()
        self.due.destroy()
        self.separator.destroy()
        pass


every_shown_hw = []


def refresh_homeworks():
    global DUE_HW_COUNTER, bin_image, every_shown_hw
    try:
        with open("data.json") as read_file:
            hw = json.load(read_file)[f'{USERNAME}']['homework']
            hw = sort_hw(hw)
    except FileNotFoundError:
        messagebox.showerror(title="File not found!", message="No data file has been found!")
    else:
        row = 4
        for subject in hw:
            # display items with show=true from HOMEWORK_LIST
            if hw[subject]['show'] is True:
                DUE_HW_COUNTER += 1
                
                x = HomeworkDisplay(hw, subject, row, col=0)
                every_shown_hw.append(x)
                row += 2


def save_hw():
    global hw_id
    hw_id += 1
    with open("id.txt", mode='w') as write_file:
        write_file.write(f"{hw_id}")
    
    subject = hw_subject_entry.get()
    due = hw_due_entry.get()
    description = hw_content_entry.get()
    
    new_homework = {
        f"{subject}": {
            "description": f"{description}",
            "due": f"{due}",
            "completed": False,
            "id": hw_id,
            "show": True
        }
    }
    field_is_empty = len(subject.strip()) == 0 or len(description.strip()) == 0 or len(due.strip()) == 0
    if field_is_empty:
        messagebox.showerror(title="EmptyFieldError!", message="Please don't leave any field empty.")
    else:
        current_user_data['homework'].update(new_homework)
        with open("data.json", mode='w') as write_file:
            json.dump(complete_data, write_file, indent=4)
        messagebox.showinfo(title='Homework Added', message="Homework has been added! ")
        
        hw_due_entry.delete(0, END)
        hw_content_entry.delete(0, END)
        hw_subject_entry.delete(0, END)
        
        notebook.tab(add_hw_tab, state='hidden')
        notebook.select(assignments_tab)
        for label in every_shown_hw:
            label.hide()
        refresh_homeworks()


def delete_widgets(title, desc, separator, del_btn):
    title.destroy()
    desc.destroy()
    separator.destroy()
    del_btn.destroy()

def show_todos():
    with open('data.json') as read_file:
        todos = json.load(read_file)[f"{USERNAME}"]['todo']
    row = 2
    for a_title in todos:
        title = Label(todo_tab, text=f'{a_title}', font=FONT, bg=WHITE)
        title.grid(row=row, column=0)  # title
        desc = Label(todo_tab, text=f"{todos[a_title]['description']}", font=FONT, justify=LEFT, bg=WHITE, fg=BLACK)
        desc.grid(row=row, column=1)
        separator = ttk.Separator(todo_tab, orient=HORIZONTAL)
        close_btn = Button()
        close_btn = Button(todo_tab, text="Remove", font=FONT, bg=WHITE, command=lambda title=title, desc=desc, separator=separator, del_btn=close_btn: delete_widgets(title, desc, separator, close_btn))
        close_btn.grid(row=row, column=2)
        separator.grid(row=row+1, column=0, columnspan=4, sticky='ew')
        row += 2


def add_bullet_point(event):
    text = event.widget
    current_line = text.index("insert linestart")
    text.insert(current_line, "• ")


def create_todo():
    global todo_content_entry, todo_title_entry, todo_save_button, todo_content_label, todo_title_label
    
    notebook.tab(add_todo_tab, state='normal')
    notebook.select(add_todo_tab)
    
    todo_create_button.configure(font=FONT)
    todo_title_label = Label(add_todo_tab, text="Title", font=FONT, padx=5, pady=0)
    todo_title_label.grid(row=1, column=0)
    todo_title_entry = Entry(add_todo_tab, font=FONT, width=40)
    
    todo_title_entry.focus()
    todo_title_entry.grid(row=2, column=0)
    
    todo_content_label = Label(add_todo_tab, text="Description: ", font=FONT)
    todo_content_label.grid(row=3, column=0)
    
    todo_content_entry = Text(add_todo_tab, font=FONT, width=40, height=6)
    todo_content_entry.bind("<Return>", add_bullet_point)
    
    todo_content_entry.grid(row=4, column=0)
    todo_save_button = Button(add_todo_tab, text="  Save  ", font=FONT, command=save_todo, cursor='hand1')
    todo_save_button.grid(row=5, column=0)


def save_todo():
    global LATEST_TODO_ID
    LATEST_TODO_ID += 1
    new_todo = Todo()
    todo_create_button.configure(state='normal')
    
    with open("todo_id.txt", mode='w') as todo_id_file:
        new_todo.id = todo_id_file.write(f'{LATEST_TODO_ID}')
    
    new_todo.title = todo_title_entry.get()
    new_todo.content = todo_content_entry.get(index1=1.0, index2="end")
    new_todo.id = LATEST_TODO_ID
    
    todo_to_be_saved = {
        f"{new_todo.title}": {
            "description": new_todo.content,
            "id": new_todo.id,
        }
    }
    
    field_is_empty = len(new_todo.title) == 0 or len(new_todo.content) == 0
    if field_is_empty:
        messagebox.showerror(title="EmptyFieldError!", message="Please don't leave any field empty.")
    else:
        current_user_data['todo'].update(todo_to_be_saved)
        with open("data.json", mode='w') as write_file:
            json.dump(complete_data, write_file, indent=4)
        messagebox.showinfo(title='Todo Added', message='Todo has been created.')
        
        todo_content_entry.delete(1.0, END)
        todo_title_entry.delete(0, END)
        notebook.tab(add_todo_tab, state='hidden')
        notebook.select(todo_tab)
        show_todos()


def n_on_leave(event):
    note_text_data = text_box.get(index1=1.0, index2='end')
    
    if note_text_data == '':
        print('a')
        text_box.insert(0, 'enter a note')


all_notes = []
note_id = 100

class Note:
    def __init__(self, row: int, column: int):
        self.text = None
        self.key = None
        self.new_note = None
        self.i = 0
        self.frame = Frame(notes_tab)
        self.frame.configure(height=260, width=200)
        self.frame.grid(row=row, column=column, padx=15, pady=10)
        self.sm_frame = Frame(self.frame, height=260, bg=GREEN)
        self.sm_frame.grid(row=row, column=column + 1, sticky='ns')
        self.sm_frame.grid_propagate(False)

        self.scrollbar = Scrollbar(self.sm_frame, orient=VERTICAL)
        self.scrollbar.pack(side=RIGHT, fill=Y)

        self.text_box = Text(self.frame, font=FONT, width=20, height=9, undo=True, yscrollcommand=self.scrollbar.set,
                             bg=LIGHT_YELLOW, pady=25, padx=3,
                             selectbackground=BLUE, wrap=WORD)
        self.text_box.focus()
        self.scrollbar.config(command=self.text_box.yview)
        self.text_box.grid(row=row, column=column, sticky='nsew')

        self.close_button = Button(self.frame, text="X", fg=BLACK, bg=RED, cursor='hand1',
                                   command=self.close)
        # self.del_button.tkraise()
        self.close_button.grid(row=row, column=column, sticky="en")

        self.save_button = Button(self.frame, text="Save", command=lambda: self.save(USERNAME), cursor='hand1',
                                  bg=LIGHT_YELLOW)
        self.save_button.grid(row=row, column=column, sticky='s')

        self.del_button = Button(self.frame, text="Delete", command=self.delete, cursor='hand1', bg=LIGHT_YELLOW)
        self.del_button.grid(row=row, column=column, sticky='se')

    def save(self, user):
        self.text = self.text_box.get(index1=1.0, index2='end').strip()
        if len(self.text.strip('\n')) > 0:
            if self.i == 0:
                self.key = f"{self.text}"
                self.i += 1
            
            with open('data.json') as read_file:
                whole_data: dict = json.load(read_file)
            user_notes = whole_data[f"{user}"]['notes']
            # self.new_note = {
            #     self.key: {
            #         "content": f"{self.text_box.get(index1=1.0, index2='end')}"
            #     }
            # }
            user_notes[self.key] = f"{self.text_box.get(index1=1.0, index2='end')}"
            print(user_notes)
            messagebox.showinfo(title="Saved", parent=notes_tab, message=f"Note has been saved:\n{self.text}")

        
    def delete(self):
        pass
    
    def close(self):
        global note_row, note_column
        self.frame.destroy()
        
    # def show_message(self):
    #     messagebox.showinfo(title="Saved", parent=self.frame, message=f"Note has been saved:\n{self.text}")

def create_note_box():
    global note_row, note_column
    
    new_note = Note(row=note_row, column=note_column)
    all_notes.append(new_note)
    
    note_column = note_column + 1
    note_column %= 3
    if note_column == 0:
        note_row = note_row + 1
        note_column = 0


# ---------------------------------- FILE HANDLING -------------------------------------- #


login_screen()  # TODO Uncomment this line on completion of code

# todo_id and sub_id handling
try:
    with open("id.txt") as id_file:
        hw_id = int(id_file.read())
except FileNotFoundError:
    with open("id.txt", mode='w') as id_file:
        first_hw_id = 100
        id_file.write(f'{first_hw_id}')

try:
    with open("todo_id.txt") as id_file:
        LATEST_TODO_ID = int(id_file.read())
except FileNotFoundError:
    with open("todo_id.txt", mode='w') as id_file:
        LATEST_TODO_ID = 10000
        id_file.write(f'{LATEST_TODO_ID}')

'''
delete this block (below) on completion of code
this block of code is set to count how many times the code has been run
'''
try:
    with open('run_counter.txt') as run_file:
        run_count = int(run_file.read())
except FileNotFoundError:
    with open('run_counter.txt', mode='w') as run_file:
        run_file.write("1")
else:
    with open('run_counter.txt', mode='w') as run_file:
        run_count += 1
        run_file.write(f"{run_count}")
        print(run_count)

# ---------------------------------- PROGRAM STARTS HERE ------------------------------------- #

if LOGGED_IN:
    try:
        with open('data.json') as file:
            complete_data = json.load(file)
            current_user_data = complete_data[f'{USERNAME}']
    except FileNotFoundError:
        with open('data.json', mode='w') as file:
            file_structure = {
                f"{USERNAME}": {
                    "homework": {},
                    "todo": {},
                    "notes": {},
                    "completed_hw": {}
                }
            }
            complete_data = file_structure
            current_user_data = file_structure[f"{USERNAME}"]
            json.dump(file_structure, file, indent=4)
    
    window = Tk()
    window.quit()
    window.bind('<Control-q>', quit_app)
    
    window.geometry("1200x600+300+200")
    window.title(string="Homework Aid")
    
    # global WIDGETS so that they can be READ/DESTROYED anywhere in the code
    hw_due_entry = Entry()
    hw_content_entry = Entry()
    hw_subject_entry = Entry()
    todo_title_label = Label()
    todo_title_entry = Entry()
    todo_content_label = Label()
    todo_content_entry = Text()
    todo_save_button = Button()
    pick_date_button = Button()
    calendar = Calendar()
    confirm_date_button = Button()
    
    text_box = Text()
    
    s_username_entry = Entry()
    s_password_entry = Entry()
    l_username_entry = Entry()
    l_password_entry = Entry()
    
    temp_frame = Frame()
    about_frame = Frame()
    signup_frame = Frame()
    
    bin_image = bin_img()
    
    style = ttk.Style(window)
    style.configure('TNotebook', background=WHITE, tabposition='wn')
    
    notebook = ttk.Notebook(window, style='left_tab.TNotebook')
    all_tabs = create_six_tabs(notebook)
    dash_tab, assignments_tab, notes_tab, todo_tab, add_hw_tab, add_todo_tab = all_tabs
    
    # ASSIGNMENT TAB
    show_headers()
    refresh_homeworks()
    
    # todo_tab
    Label(todo_tab, text="Anything you want to do later? Add them here.",bg=WHITE, font=FONT).grid(row=0, column=0, columnspan=2)
    todo_create_button = Button(todo_tab, text="Create", command=create_todo, cursor='hand1', font=FONT,
                                background='white', borderwidth=0)
    todo_create_button.grid(row=0, column=2)
    ttk.Separator(todo_tab, orient=HORIZONTAL).grid(row=1, column=0, columnspan=6, sticky='ew')
    show_todos()
    
    # note tab  
    Button(notes_tab, text='New Note', cursor='hand1', bg=BLUE, fg=BLACK, font='24',
           command=create_note_box).grid(row=0, column=0, sticky='n', padx=20)
    create_note_box()
    create_note_box()
    
    # DASH TAB
    Label(dash_tab, text="Welcome to your HomeWork assistance system", font=FONT, pady=10, background=RED) \
        .grid(row=1, column=1)
    Label(dash_tab, text=f"You have {DUE_HW_COUNTER} homeworks remaining", font=FONT, pady=10, background=WHITE).grid(
        row=2, column=1)
    search_box = Entry(dash_tab, width=30, font=FONT)
    search_box.grid(row=1, column=3, padx=100)
    search_box.focus()
    
    # word finder
    
    assignment_words = (get_label_text(assignments_tab))
    dash_words = (get_label_text(dash_tab))
    todo_words = (get_label_text(todo_tab))
    note_words = (get_label_text(notes_tab))
    
    dash_words = selection_sort(dash_words)
    todo_words = selection_sort(todo_words)
    assignment_words = selection_sort(assignment_words)
    note_words = selection_sort(note_words)

    def select_tab(tab_no):
        notebook.select(tab_no)


    frame = Frame(dash_tab)
    
    
    def search_and_show(word, *word_lists):
        global frame
        found = False
        for widget in frame.winfo_children():
            widget.destroy()
        frame.grid(row=4, column=3, columnspan=2)
        tree = ttk.Treeview(frame)
        tree.heading('#0', text="Result")
    
        if word in word_lists[0][0]:
            tree.insert(parent='', index='end', iid=0, text=f"'{word}' found in dash")
            found = True
        if word in word_lists[0][1]:
            tree.insert(parent='', index='end', iid=1, text=f"'{word}' found in assignment")
            found = True
        if word in word_lists[0][2]:
            tree.insert(parent='', index='end', iid=3, text=f"'{word}' found in todo")
            found = True
        if word in word_lists[0][3]:
            tree.insert(parent='', index='end', iid=2, text=f"'{word}' found in notes")
            found = True
        if not found:
            tree.insert(parent='', index='end', iid=0, text=f"'{word}' not found.")
    
        def on_select(event):
            item = tree.selection()[0]
            select_tab(item)
    
        tree.pack()
        tree.focus_set()
        tree.selection_set(tree.get_children()[0])
        tree.bind('<Return>', on_select)


    words = (dash_words, assignment_words, todo_words, note_words)
    Label(dash_tab, text="Search for any word in this app", bg=WHITE).grid(row=2, column=3)
    Button(dash_tab, text="Search", font=FONT, cursor='hand1', bg=BLUE,
           command=lambda: search_and_show(search_box.get(), words)).grid(row=3, column=3, pady=20)
    
    # print(dash_words)
    
    window.mainloop()
