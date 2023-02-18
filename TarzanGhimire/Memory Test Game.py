import pygame as pg
import time
from random import randint
import sys
pg.init()


clock=pg.time.Clock()
font=pg.font.Font('freesansbold.ttf',40)

display_surface = pg.display.set_mode((1000, 800))

pg.display.set_caption('Memory Test')
color = pg.Color('chartreuse4')

count = 0
nume=''
s=0

def displayy(thetext):
    global s
    
    if (s % 2==0):
        white=(255,255,255)
        green=(150,150,0)
        blue=(0,150,150)
    else:
        white=(255,255,255)
        green=(0,150,150)
        blue=(150,150,0)
    s+=1  
    text = font.render(thetext, True, white, green)
    textRect=text.get_rect()
    textRect.center=(1000 // 2,800 //2)
    display_surface.fill(blue)
    display_surface.blit(text, textRect)
    
   
def oneone(nume):
    
    nume=str(nume)
    print(nume)
    i=0
    while i<10:
        print(nume[i])       
        displayy(f"{nume[i]}")       
        pg.display.update()
        time.sleep(0.6)
        i+=1

def check(num):
    input_rect = pg.Rect(300, 300, 1000, 50) 
    user_text = ''
    m=0
    n=0
    while m<11 :
        for event in pg.event.get():
                    if event.type == pg.KEYDOWN:
                        
                        print(num[m])
                        if event.unicode == num[m]:
                            user_text += event.unicode
                            
                           
                            if user_text==num:
                                
                                
                                
                                n=12
                                
                            m+=1
        
                            
                        else:
                            
                            n=13
                            
                            
        display_surface.fill(color)                      
        pg.draw.rect(display_surface, color, input_rect)   
        text_surface = font.render(user_text, True, (255, 255, 255))
        display_surface.blit(text_surface, (input_rect.x+5, input_rect.y+5))
        input_rect.w = max(150, text_surface.get_width()+10)
        pg.display.flip()
        clock.tick(60)
        if n==12:
            time.sleep(2)
            displayy("CONGRATULATIONS!!")
            
            pg.display.update()
            time.sleep(5)
            pg.quit()
            sys.exit()
        if n==13:
            print("sorry")
                            
            
            displayy("Sorry Try Again")
            
            pg.display.update()
            time.sleep(5)
            pg.quit()
            sys.exit()



x1=x2=x3=x4=x5=0

while True:
    for event in pg.event.get():
 
        if(count==0):
        
            displayy('Welcome (Hit Enter)')
            
         
        if event.type == pg.QUIT:
 
           
            pg.quit()
 
            quit()
 
       
        pg.display.update()
        
        if event.type==pg.KEYDOWN:
            count+=1
                
        if count==1:
            
            while x1==0:
                x1+=1
                displayy("Rule: Phone numbers will be displayed (Hit Enter)")
               
        
            
        if count==2:
            
            while x2==0:
                displayy("Guess it in order as in queue i.e FIFO (Hit Enter)")
                x2+=1

            
            
        if count==3:
            
            while x3==0:
                num=randint(9800000000,9899999999)
                print(f"num is {num}")
                oneone(num)
                displayy("Now to start guessing hit ENTER")
                numq=str(num)
                pg.display.update()
                x3+=1
        if count==4:
           
            while x4==0:
                check(numq)            
                x4+=1 
