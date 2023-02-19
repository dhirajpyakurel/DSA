import time
def bubble_sort(data,drawData,timeTick):
    for i in range(len(data)-1,0,-1):
        for j in range(i):
            if data[j]>data[j+1]:
                data[j] , data[j+1] = data[j+1],data[j]
                drawData(data,['yellow'if x==j or x== j+1 else "#A90042"for x in range(len(data))])
                timeTick =  timeTick
                time.sleep(timeTick)
    drawData(data,['green'for x in range(len(data))])
                
    


