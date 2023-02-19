from PIL import Image, ImageTk
from tkinter import PhotoImage


def bin_img():
    login_btn_img = Image.open("images/bin.png")
    resize_image = login_btn_img.resize((30, 30))
    img = ImageTk.PhotoImage(resize_image)
    return img


def login_bth_image():
    """returns login image required for login button  """
    login_btn_img = Image.open("images/login-button-png.png")
    login_btn_img = login_btn_img.resize((100, 40))
    login_btn_img = ImageTk.PhotoImage(login_btn_img)
    
    return login_btn_img


def signup_btn_image():
    """returns signup image required for signup button """
    signup_btn_img = Image.open("images/signup-button-img.png")
    signup_btn_img1 = signup_btn_img.resize((100, 40))
    signup_btn_img2 = ImageTk.PhotoImage(signup_btn_img1)
    return signup_btn_img2


def signup_btn_image2():
    """returns signup image required for signup button """
    login_btn_img = Image.open("images/signup-button-img2.png")
    login_btn_img = login_btn_img.resize((100, 40))
    login_btn_img = ImageTk.PhotoImage(login_btn_img)

    return login_btn_img

