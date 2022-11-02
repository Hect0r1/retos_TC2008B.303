size(400, 400)

def drawLine(x1, y1, x2, y2):
    tempIndex = 1
    if x1 > x2:
        tempIndex = -1
    dx = x2 - x1;
    dy = y2 - y1;
    for x in range(x1 , x2 + 1, tempIndex):
        y = y1 + dy * (x - x1) / dx;
        point(x, y)

drawLine(1,2,100,20)
drawLine(10,200,50,10)
drawLine(300,300,10,10)
drawLine(200,300,250,50)
drawLine(350,350,100,300)
