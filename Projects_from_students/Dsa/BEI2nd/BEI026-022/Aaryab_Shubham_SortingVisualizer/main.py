from tkinter import *
from tkinter import ttk #ttk stands for themed tkinter
import customtkinter
from bubblesort import bubble_sort
import random
from quicksort import quick_sort
from merge_sort import merge_sort
from selection_sort import selection_sort
main = Tk()
main.title("Sorting Visualizer")
main.geometry('900x650+400+80') #+400 and + 80 is set where i want my window to pop out
main.config(bg="#082A46")
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
mainlabel.place(x=0,y=0)


algo_menu = ttk.Combobox(main,width = 15,font = ('new roman',19,"bold"),textvariable=selected_algorithm,
            values=['Bubble Sort','Merge Sort',"Quick Sort","Selection Sort"])
algo_menu.place(x =145,y=0)
algo_menu.current(0) #by default bubble sort

random_generate  = Button(main,text="Generate",bg="#D50505",font = ("times",12," bold"),relief = RAISED,
                activebackground="#F28407",activeforeground="white",bd=5,width=10,command = Generated)
random_generate.place(x = 750,y=60)

sizevaluelabel = Label(main, text = "Size", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 10,fg = 'black',relief = GROOVE,bd=5 ,anchor = W)
sizevaluelabel.place(x=0,y=60)

sizevalue = Scale(main,from_=1,to = 30, resolution =1 ,orient = HORIZONTAL,font = ("times",14,"bold"),
            relief=RIDGE,bd=2,width =10)
sizevalue.place(x=120,y=60)


minvaluelabel = Label(main, text = "Min Value", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 10,fg = 'black',relief = GROOVE,bd=5,anchor= W )
minvaluelabel.place(x=250,y=60)

minvalue = Scale(main,from_=0,to = 10, resolution =1 ,orient = HORIZONTAL,font = ("times",14,"bold"),
            relief=RIDGE,bd=2,width =10)
minvalue.place(x=370,y=60)



maxvaluelabel = Label(main, text = "Max Value", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 10,fg = 'black',relief = GROOVE,bd=5 ,anchor= W)
maxvaluelabel.place(x=500,y=60)

maxvalue = Scale(main,from_=0,to = 100, resolution =1 ,orient = HORIZONTAL,font = ("times",14,"bold"),
            relief=RIDGE,bd=2,width =10)
maxvalue.place(x=620,y=60)

start =Button(main,text="Start",bg="#04f900",font = ("times",12,"bold"),relief = RAISED,
                activebackground="#F28407",activeforeground="white",bd=5,width=10,command=StartAlgorithm)
start.place(x = 750,y=0)

speedlabel = Label(main, text = "Time Delay", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 10,fg = 'black',relief = GROOVE,bd=5 ,anchor=W)
speedlabel.place(x=400,y=0)

speedscale = Scale(main,from_=0.1,to = 5, resolution =0.2 ,length=200,digits=2,orient = HORIZONTAL,font = ("arial",14,"bold"),
            relief=GROOVE,bd=2,width =10)
speedscale.place(x=520,y=0)


namelabel = Label(main, text = "Developed by : AARYAB PANTA , SHUBHAM RAJ PAUDEL ", font = ("new roman",16,"bold"),bg="#0E6DA5",
                width = 66,fg = 'black',relief = GROOVE,bd=5,anchor=W )
namelabel.place(x=10,y=600)
canvas = Canvas(main,width=870,height = 450,bg = 'black')
canvas.place(x=10,y=130)
main.mainloop()