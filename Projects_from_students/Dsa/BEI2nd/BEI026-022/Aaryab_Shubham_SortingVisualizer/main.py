from tkinter import *
from tkinter import font
from tkinter import ttk 
import customtkinter
from bubblesort import bubble_sort
import random
from quicksort import quick_sort
from merge_sort import merge_sort
from selection_sort import selection_sort
from message import *
from insertion import insertion_Sort
main = Tk()
main.title("Sorting Visualizer")
main.geometry('1400x670+50+50') 
main.config(bg="#082A46")
main.resizable(False,False)
message = message_begin
def clear():
    text_box.delete(1.0,END)

def Info():
    if selected_algorithm.get() == "Quick Sort":
     message = message_qucik

    elif selected_algorithm.get() == "Merge Sort":
        message = message_merge
    
    elif selected_algorithm.get() == "Bubble Sort":
        message = message_bubble
    
    elif selected_algorithm.get() == "Selection Sort":
        message = message_selection

    elif selected_algorithm.get() == "Insertion Sort":
        message = message_insert
    
    else:
        message = message_begin

    
    text_box.config(state=NORMAL)
    clear()
    text_box.insert('end',message)
    text_box.config(state=DISABLED)

def StartAlgorithm():
    global data
    if not data :
        return
    
    if (algo_menu.get() == 'Quick Sort'):
        quick_sort(data,0,len(data)-1,drawData,speedscale.get())
        drawData(data,['green' for x in range(len(data))] )

    elif algo_menu.get()=="Bubble Sort":
        bubble_sort(data,drawData,speedscale.get())
    
    elif algo_menu.get() == "Merge Sort":
        merge_sort(data,drawData,speedscale.get())
        drawData(data,['green' for x in range(len(data))] )

    elif algo_menu.get() == "Selection Sort":
        selection_sort(data,drawData,speedscale.get())
    
    elif algo_menu.get() == "Insertion Sort":
        insertion_Sort(data,drawData,speedscale.get())

def drawData(data,colorArray):
    canvas.delete('all')
    canvas_height = 450
    canvas_width = 870
    x_width = canvas_width / (len(data)+1)
    offset = 10
    spacing_bet_rect = 10
    normalised_data = [i / max(data) for i in data]

    for i ,height in enumerate(normalised_data):
        x0 = i*x_width + offset + spacing_bet_rect
        y0 = canvas_height - height *400  #we have multiplied 400 because we will normalised our values with one
                                           # formila so that our data won't exceed our canvas
        x1 = (i+1) * x_width
        y1 = canvas_height

        canvas.create_rectangle(x0,y0,x1,y1,fill = colorArray[i])
        canvas.create_text((x0+2),y0,anchor=  SW,text = str(data[i]),font = ("new roman",15,"bold"),fill = "white")
    main.update_idletasks()

def Generated():
    global data
    print("Selected Algorithm: "+ selected_algorithm.get())
    try:
        minivalue = minvalue.get()
    except:
        minivalue = 1
    try:
        maxivalue = maxvalue.get()
    except:
        maxivalue = 100
    try:
        size = sizevalue.get()
    except:
        size = 10  
    data = []

    if minivalue < 0:
        minivalue = 0
    if maxivalue > 100:
        maxivalue =100
    if size > 30:
        size = 30 

    if minivalue > maxivalue:
        minivalue,maxivalue = maxivalue, minivalue
    
    
    for _ in range(size):
        data.append(random.randint(minivalue,maxivalue))
    drawData(data,["#082A46" for x in range (len(data))])


selected_algorithm = StringVar()
#label, buttons ,speed scale


mainlabel = Label(main, text = "Algorithm", font = ("new roman",16,"bold"),bg="#05897A",
                width = 10,fg = 'black',relief = GROOVE,bd=5,anchor= W )
mainlabel.grid(row=0,column=0)


algo_menu = ttk.Combobox(main,width = 15,font = ('new roman',19,"bold"),textvariable=selected_algorithm,
            values=['Bubble Sort','Merge Sort',"Quick Sort","Selection Sort","Insertion Sort"])
algo_menu.grid(row = 0 , column =1,padx=5)
algo_menu.current(0) #by default bubble sort

speedlabel = Label(main, text = "Time Delay", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 10,fg = 'black',relief = GROOVE,bd=5 ,anchor=W)
speedlabel.grid(row = 0,column=2,padx=5)

speedscale = Scale(main,from_=0.1,to = 5, resolution =0.2 ,length=200,digits=2,orient = HORIZONTAL,font = ("arial",14,"bold"),
            relief=GROOVE,bd=2,width =10)
speedscale.grid(row= 0 , column= 3,padx = 5)

start =Button(main,text="Start",bg="#04f900",font = ("times",12,"bold"),relief = RAISED,
                activebackground="#F28407",activeforeground="white",bd=5,width=10,command=StartAlgorithm)
start.grid(row=0,column= 4,padx=5)


sizevaluelabel = Label(main, text = "Size", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 10,fg = 'black',relief = GROOVE,bd=5 ,anchor = W)
sizevaluelabel.grid(row=2,column=0)

sizevalue = Scale(main,from_=1,to = 30, resolution =1 ,orient = HORIZONTAL,font = ("times",14,"bold"),
            relief=RIDGE,bd=2,width =10,length=200)
sizevalue.grid(row=2,column=1,padx= 0)


minvaluelabel = Label(main, text = "Min Value", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 10,fg = 'black',relief = GROOVE,bd=5,anchor= W )
minvaluelabel.grid(row=1,column=0)

minvalue = Scale(main,from_=0,to = 10, resolution =1 ,orient = HORIZONTAL,font = ("times",14,"bold"),
            relief=RIDGE,bd=2,width =10,length=200)
minvalue.grid(row=1,column=1,pady=5)



maxvaluelabel = Label(main, text = "Max Value", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 10,fg = 'black',relief = GROOVE,bd=5 ,anchor= W)
maxvaluelabel.grid(row = 1,column=2)

maxvalue = Scale(main,from_=0,to = 100, resolution =1 ,orient = HORIZONTAL,font = ("times",14,"bold"),
            relief=RIDGE,bd=2,width =10,length=200)
maxvalue.grid(row=1,column=3)

random_generate  = Button(main,text="Generate",bg="#D50505",font = ("times",12," bold"),relief = RAISED,
                activebackground="#F28407",activeforeground="white",bd=5,width=10,command = Generated)
random_generate.grid(row = 1,column = 4)

info_generate  = Button(main,text="How it Works?",bg="#FFFF28",font = ("times",12," bold"),relief = RAISED,
                activebackground="#F28407",activeforeground="white",bd=5,width=11,command = Info)
info_generate.grid(row = 2,column = 2)



namelabel = Label(main, text = "Developed by : AARYAB PANTA , SHUBHAM RAJ PAUDEL ", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 66,fg = 'black',relief = GROOVE,bd=5,anchor=W )
namelabel.place(x=10,y =625)
canvas = Canvas(main,width=870,height = 450,bg = 'black')
canvas.place(x=10,y=160)
text_box = Text(main,height=25,width=40,font = ("Calibri Light",16,"bold"),bg="#0E6DA5",
                fg = 'black',relief = GROOVE,bd=5 ,wrap=WORD)
text_box.insert('end',message)
text_box.config(state=DISABLED)
text_box.place(x = 900,y=0)
main.mainloop()