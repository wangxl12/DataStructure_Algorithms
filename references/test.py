import turtle as t
t.pensize(4) # 设置画笔的大小
t.colormode(255) # 设置GBK颜色范围为0-255
t.color((255,155,192),"pink") # 设置画笔颜色和填充颜色(pink)
t.setup(840,500) # 设置主窗口的大小为840*500
t.speed(1) # 设置画笔速度为10

t.color("red",(255,99,71))
# t.goto(-100,100) # 画笔前往坐标(-100,100)
t.pu() # 提笔
t.seth(90) # 设置角度
t.fd(-20) # 向后移动20
t.seth(0)
t.fd(-78)
t.pd() # 落笔
t.begin_fill() # 外形填充的开始标志
t.seth(-130)
t.circle(100,10)
t.circle(300,30)
t.seth(0)
t.fd(230)
t.seth(90)
t.circle(300,30)
t.circle(100,3)
t.color((255,155,192),(255,100,100))
t.seth(-135)
t.circle(-80,63)
t.circle(-150,24)
t.end_fill()
t.done()