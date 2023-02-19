import time
def selection_sort(data,drawData,timeTick):
    for i in range(len(data)):
        min_idx = i
        for j in range(i+1, len(data)):
            if data[min_idx] > data[j]:
                min_idx = j
        data[i], data[min_idx] = data[min_idx], data[i]
        drawData(data,['yellow' if x == i or x == min_idx else '#A90042'for x in range(len(data))])
        time.sleep(timeTick)
    drawData(data,['green'for x in range(len(data))])




