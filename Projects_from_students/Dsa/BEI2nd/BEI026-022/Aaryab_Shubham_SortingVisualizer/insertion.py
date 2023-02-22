import time
def insertion_Sort(arr,drawData,timeTick):
    for i in range(1, len(arr)):
        drawData(arr,['#A90042'for x in  range(0,len(arr))])
        time.sleep(timeTick)
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                drawData(arr,['yellow'if x == j else '#A90042' for x in range(0,len(arr))])
                time.sleep(timeTick)
                j -= 1
        arr[j + 1] = key
        drawData(arr,['yellow'if x == j+1 else '#A90042' for x in range(0,len(arr))])
        time.sleep(timeTick)
    drawData(arr,['green' for x in range(0,len(arr))])


