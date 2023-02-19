from tkinter import *
from tkinter import filedialog, messagebox
import re
import pickle
import rsa
import base64

# window initialization
window = Tk()
window.title("JATE ( Just Another Text Editor   )")
window.geometry("1100x600")
window.resizable(True, True)
window.configure(background="#242B2E")

# variables for file open status
global open_file_status
open_file_status = False

# variable fot text text selection status
global is_selected
is_selected = False


# keys creation  for rsa encryption
global private_key, public_key
try:
    with open("keys.pickle", "rb") as f:
        public_key, private_key = pickle.load(f)
except FileNotFoundError:
    (public_key, private_key) = rsa.newkeys(512)
    with open("keys.pickle", "wb") as f:
        pickle.dump((public_key, private_key), f)

global encrypted_text
encrypted_text = ""

global encrypted_text_caesar
encrypted_text_caesar = ""

# -----------------file menu functions---------------------
# creating a new file


def new_file(e):
    # remove the previous text
    text_box.delete(1.0, END)
    # update  the status bar
    window.title("untitled.txt")
    status_bar.config(text="New File  ")

    global open_file_status
    open_file_status = False

# opening a file


def open_file(e):
    text_file = filedialog.askopenfilename(parent=window,  initialdir="E:/", title="Open File",
                                           filetypes=(
                                               ("Text Files", "*.txt"),
                                               ("C++ Files", "*.cpp"),
                                               ("Python Files", "*.py"),
                                               ("C Files", "*.c"),
                                               ("HTML Files", "*.html"),
                                               ("All Files", "*.*")

                                           )
                                           )

    if text_file:
        name = text_file
        status_bar.config(text=f"{name}  ")
        window.title(f"{name}")

    # inserting text to the file
        text_file = open(text_file, 'r')
        lines = text_file.read()
        text_box.insert(END, lines)
        text_file.close()

    else:
        print("no file selected")

# saving file


def save_as_file(e):
    text_file = filedialog.asksaveasfilename(parent=window,  initialdir="E:/", title="Save File as",
                                             filetypes=(
                                                 ("Text Files", "*.txt"),
                                                 ("C++ Files", "*.cpp"),
                                                 ("Python Files", "*.py"),
                                                 ("C Files", "*.c"),
                                                 ("HTML Files", "*.html"),
                                                 ("All Files", "*.*")

                                             )
                                             )

    if text_file:
        name = text_file
        status_bar.config(text=f"Saved: {name}  ")
        name = name.replace("E:\    ", "")
        window.title(f"{name}")

    # the real save

        text_file = open(text_file, 'w')
        text_file.write(text_box.get(1.0, END))
        text_file.close()
    else:
        print("no file selected")

# save the opened file


def save_file(e):
    global open_file_status
    if open_file_status:
        text_file = open(open_file_status, 'w')
        text_file.write(text_box.get(1.0, END))
        text_file.close()
        status_bar.config(text=f'Saved: {open_file_status}        ')
    else:
        save_as_file(e)

# -------------------sorting functons-------------------------


def merge_sort(lst):
    if len(lst) <= 1:
        return lst
    mid = len(lst)//2
    left_half = lst[:mid]
    right_half = lst[mid:]
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)
    return merge(left_half, right_half)


def merge(left_half, right_half):
    merged_list = []
    left_index = 0
    right_index = 0
    while left_index < len(left_half) and right_index < len(right_half):
        if left_half[left_index] < right_half[right_index]:
            merged_list.append(left_half[left_index])
            left_index += 1
        else:
            merged_list.append(right_half[right_index])
            right_index += 1
    merged_list += left_half[left_index:]
    merged_list += right_half[right_index:]
    return merged_list


def sort_ascending():
    text = text_box.get(1.0, END)
    lines = text.split('\n')
    sorted_text = merge_sort(lines)
    text_box.delete(1.0, END)
    for line in sorted_text:
        text_box.insert(END, line + "\n")


def sort_descending():
    text = text_box.get(1.0, END)
    lines = text.split('\n')
    sorted_text = merge_sort(lines)[::-1]
    text_box.delete(1.0, END)
    for line in sorted_text:
        text_box.insert(END, line + "\n")


# -------------------cut copy paste-------------------------
def cut_text(e):
    global is_selected

    if e:
        is_selected = window.clipboard_get()
    else:
        if text_box.selection_get():
            is_selected = text_box.selection_get()
            text_box.delete("sel.first", "sel.last")
            window.clipboard_clear()
            window.clipboard_append(is_selected)


def copy_text(e):
    global is_selected

    if e:
        is_selected = window.clipboard_get()
    else:
        if text_box.selection_get():
            is_selected = text_box.selection_get()
            window.clipboard_clear()
            window.clipboard_append(is_selected)


def paste_text(e):
    global is_selected
    # check keyboard shortcuts action
    if e:
        is_selected = window.clipboard_get()

    else:
        if is_selected:
            position = text_box.index(INSERT)
            text_box.insert(position, is_selected)


def select_all(e):
    #text = text_box.get(1.0, END).strip()
    text_box.tag_add('sel', '1.0', END)


# -------------------searching-------------------------
def search_text(e):

    #global word
    # search box parameters
    search_box = Toplevel(window)
    search_box.title("Find text")
    search_box.transient(window)
    search_box.resizable(False, False)
    search_box.geometry("300x100")
    search_label = Label(search_box, text="Find Text(Binary Search)")
    search_label.pack(pady=5)

    # text box to enter the text to search
    entry_widget = Entry(search_box, width=25)
    entry_widget.focus_set()
    entry_widget.pack(pady=5)

    def perform_search():
        word = entry_widget.get()
        check_for_word(word)
        search_box.destroy()

    def cancel_search():
        search_box.destroy()

    # search and cancel buttons

    search_button = Button(search_box, text="Search", command=perform_search)
    search_button.pack(padx=15, ipadx=15, side=RIGHT)

    cancel_button = Button(search_box, text="Cancel", command=cancel_search)
    cancel_button.pack(pady=5, padx=15, ipadx=15, side=LEFT)

    def check_for_word(word):
        text_box.tag_remove('found', "1.0", "end")
        text_box.tag_config('found', foreground='white', background='blue')

        word_list = text_box.get(1.0, END).split('\n')
        sorted_words = merge_sort(word_list)
        left = 0
        right = len(sorted_words) - 1

        while left <= right:
            mid = (left + right)//2

            if sorted_words[mid] == word:
                start = text_box.search(word, 1.0, nocase=1, stopindex=END)
                end = '%s+%dc' % (start, len(word))
                text_box.tag_add('found', start, end)
                start = end
                left = mid+1
                text_box.see(end)
            elif sorted_words[mid] < word:
                left = mid + 1
            else:
                right = mid - 1
        return -1


# -------------------regex search-------------------------
def regex_search(e):

    def cancel_search():
        text_box.tag_remove('found', "1.0", "end")
        search_box.destroy()
        return "break"

    search_index = "1.0"
    # search box parameters
    search_box = Toplevel(window)
    search_box.title("Find text(Regex Search)")
    search_box.transient(window)
    search_box.resizable(False, False)
    search_box.geometry("300x100")
    search_label = Label(search_box, text="Find")
    search_label.pack(pady=5)

    # text box to enter the text to search
    entry_widget = Entry(search_box, width=25)
    entry_widget.focus_set()
    entry_widget.pack(pady=5)

    def perform_regex_search():
        word = entry_widget.get()
        do_regex_search(word)

    def cancel_search():
        search_box.destroy()
    # search and cancel buttons
    search_button = Button(search_box, text="Search",
                           command=perform_regex_search)
    search_button.pack(padx=15, ipadx=15, side=RIGHT)

    cancel_button = Button(search_box, text="Cancel", command=cancel_search)
    cancel_button.pack(pady=5, padx=15, ipadx=15, side=LEFT)

    def do_regex_search(word):
        nonlocal search_index
        text_box.tag_remove('found', "1.0", "end")
        text_box.tag_config('found', foreground='white', background='blue')
        #pattern = re.compile(re.escape(word),re.IGNORECASE)
        start = text_box.search(
            word, search_index, stopindex="end", regexp=True)
        #matches = pattern.search(word,search_index)
        if start:
            end = f"{start} + {len(word)}c"
            text_box.tag_add('found', start, end)
            search_index = end
            text_box.see(end)
        else:
            search_index = "1.0"
            text_box.tag_remove("found", "1.0", "end")

 # -------------------encryption-------------------------


def encrypt_text_rsa():
    global encrypted_text
    encrypted_text = ""
    text = text_box.get(1.0, END).strip()
    text_bytes = text.encode()
    encrypted_bytes = rsa.encrypt(text_bytes, public_key)
    encrypted_text = base64.b64encode(encrypted_bytes).decode()
    text_box.delete(1.0, END)
    text_box.insert(1.0, encrypted_text)


def decrypt_text_rsa():
    global encrypted_text
    plaintext = rsa.decrypt(base64.b64decode(encrypted_text), private_key)
    text_box.delete(1.0, END)
    text_box.insert(1.0, plaintext)

# -------------------caesar cipher-------------------------


def caesar_cipher_encrypt():
    global encrypted_text_caesar
    encrypted_text_caesar = ""
    text = text_box.get(1.0, END).strip()
    key = 10
    chipher_text = ""
    for char in text:
        chipher_text = chr((ord(char)+key))
        encrypted_text_caesar += chipher_text
    text_box.delete(1.0, END)
    text_box.insert(1.0, encrypted_text_caesar)


def caesar_cipher_decrypt():
    global encrypted_text_caesar
    key = -10
    plain_text = ""
    decrypted_text = ""
    for char in encrypted_text_caesar:
        plain_text = chr((ord(char)+key))
        decrypted_text += plain_text
    text_box.delete(1.0, END)
    text_box.insert(1.0, decrypted_text)

  # -------------------about-------------------------


def about():
    messagebox.showinfo("About", " JATE: (Just another text editor) \n Version: 1.0.0_beta \n Author: Biplop Giri",
                        )


def quit_window(e):
    window.quit()


# --------GUI functions----------------

main_frame = Frame(window)
main_frame.pack(ipady=5)

# vertical scrollbar
vertical_scroll = Scrollbar(main_frame)
vertical_scroll.pack(side=RIGHT, fill=Y)

# horizontal scrollbar
horizontal_scroll = Scrollbar(main_frame, orient=HORIZONTAL)
horizontal_scroll.pack(side=BOTTOM, fill=X)


text_box = Text(main_frame, width=97, height=25, font=("Helvetica", 16), background="#CAB5D2",
                foreground="black", insertbackground="Black",
                selectbackground="blue", selectforeground="white", selectborderwidth=0,
                undo=True,
                yscrollcommand=vertical_scroll.set, xscrollcommand=horizontal_scroll.set
                )
text_box.pack()


vertical_scroll.config(command=text_box.yview)
horizontal_scroll.config(command=text_box.xview)


menu_font = ('Segoe UI', 11, 'bold')
bg_color = "#333333"
fg_color = "#FFFFFF"


# A menu to bind all the functions
main_menu = Menu(window)
window.config(menu=main_menu)

# Menu for different file operations

file_menu = Menu(main_menu, tearoff=False)
main_menu.add_cascade(label=" File         ", menu=file_menu,
                      font=menu_font, foreground="#383CC1")
file_menu.add_command(label=" New          ",
                      command=lambda: new_file(False), accelerator="(Ctrl+n)")
file_menu.add_command(label=" Open         ",
                      command=lambda: open_file(False), accelerator="(Ctrl+o)")
file_menu.add_command(label=" Save         ",
                      command=lambda: save_file(True), accelerator="(Ctrl+s)")
file_menu.add_command(label=" Save As      ",
                      command=lambda: save_as_file(False), accelerator="(Ctrl+Shift+s)")
file_menu.add_command(label=" Exit         ",
                      command=lambda: quit_window(False), accelerator="(Ctrl+q)")

# Menu for edition operations
edit_menu = Menu(main_menu, tearoff=False)
main_menu.add_cascade(label=" Edit          ",
                      menu=edit_menu, font=menu_font, foreground="#383CC1")
edit_menu.add_command(label=" Cut           ",
                      command=lambda: cut_text(False), accelerator="(Ctrl+x)")
edit_menu.add_command(label=" Copy          ",
                      command=lambda: copy_text(False), accelerator="(Ctrl+c)")
edit_menu.add_command(label=" Paste         ",
                      command=lambda: paste_text(False), accelerator="(Ctrl+v)")
edit_menu.add_separator()
edit_menu.add_command(label=" Undo          ",
                      command=text_box.edit_undo, accelerator="(Ctrl+z)")
edit_menu.add_command(label=" Redo          ",
                      command=text_box.edit_redo, accelerator="(Ctrl+y)")
edit_menu.add_separator()
edit_menu.add_command(label=" Select All     ",
                      command=lambda: select_all(True), accelerator="(Ctrl+A)")

# Kyboard shortcuts for edition operations

# The sorting menu
sort_menu = Menu(main_menu, tearoff=False)
main_menu.add_cascade(label=" Sort         ", menu=sort_menu,
                      font=menu_font, foreground="#383CC1")
sort_menu.add_command(label=" Sort Ascending", command=sort_ascending)
sort_menu.add_command(label=" Sort Descending", command=sort_descending)


# The code format menu


# The search menu
search_menu = Menu(main_menu, tearoff=False)
main_menu.add_cascade(label=" Search       ",
                      menu=search_menu, font=menu_font, foreground="#383CC1")
search_menu.add_command(label="  Binary Search",
                        command=lambda: search_text(False))
search_menu.add_command(label=" Regex Search",
                        command=lambda: regex_search(False))


# code format menu
encrypt_menu = Menu(main_menu, tearoff=False)
main_menu.add_cascade(label="   Encrypt    ",
                      menu=encrypt_menu, font=menu_font, foreground="#383CC1")
encrypt_menu.add_command(label="     RSA        ", command=encrypt_text_rsa)
encrypt_menu.add_command(label=" Caesar Cipher",
                         command=caesar_cipher_encrypt)

decrypt_menu = Menu(main_menu, tearoff=False)
main_menu.add_cascade(label="   Decrypt  ", menu=decrypt_menu,
                      font=menu_font, foreground="#383CC1")
decrypt_menu.add_command(label="     RSA        ", command=decrypt_text_rsa)
decrypt_menu.add_command(label=" Caesar Cipher",
                         command=caesar_cipher_decrypt)


status_bar = Label(window, text="Ready ", background="#CAB5D2",
                   fg="black", font=("Segoe UI", 10, 'bold'))
status_bar.pack(fill=X, side=BOTTOM, ipady=5)


# keyboard shortcuts
window.bind('<Control-Key-x>', cut_text)
window.bind('<Control-Key-c>', copy_text)
window.bind('<Control-Key-v>', paste_text)
window.bind('<Control-Key-a>', select_all)
window.bind('<Control-Key-o>', open_file)
window.bind('<Control-Key-s>', save_file)
window.bind('<Control-Key-s>', save_as_file)
window.bind('<Control-Key-q>', quit_window)
window.bind('<Control-Key-n>', new_file)
window.bind('<Control-Key-f>', search_text)
window.bind('<Control-Key-r>', regex_search)


window.mainloop()
