
import turtle as p
import random


"""turtle.hideturtle() #将画笔隐藏
turtle.setup(width,height,startx,trarty):设置窗体大小
turtle.goto(x,y):直接到达（x,y）位置
turtle.fd(d):朝海龟的正前方前进 turtle.forward(d) 功能类似
turtle.bk(d):朝海龟的后方前进 turtle.forward(d) 功能类似
turtle.circle(r,angle):以海龟左侧一点为圆心曲线运行
turtle.seth(angle):改变海龟的行进角度 (绝对角度)
turtle.left(angle):改变海龟的行进角度(海龟的左方)
turtle.right(angle)：改变海龟的行进角度 (海龟的右方)
turtle.tracer(False) ：设置动画开关来加速绘画，不显示过程。默认为ture显示过程
p.mainloop() ：在最后画图执行的命令或者p.done()
"""

def snow(snow_count):  #绘制雪花漫天
    p.hideturtle()      #将画笔隐藏
    p.speed(10)         #画笔移动速度[1,10]
    p.pensize(3)        #画笔的大小
    for i in range(snow_count):
        r = random.random()
        g = random.random()
        b = random.random()
        p.pencolor(r, g, b)  #画笔颜色（支持“red","green"或者rbg三元组）
        p.pu()               #p.penup() 抬起画笔
        p.goto(random.randint(-350, 350), random.randint(1, 270)) #设定画笔位置
        p.pd()              #p.pendown() #画笔落下
        dens = random.randint(8, 12)
        snowsize = random.randint(10, 14)
        for _ in range(dens):   #由一个点画雪花图案的过程
            p.forward(snowsize)   # p.fd()向当前画笔方向移动snowsize像素长度
            p.backward(snowsize)  # p.bk()向当前画笔相反方向移动snowsize像素长度
            p.right(360 / dens)  # 顺时针移动360 / dens度

def ground(ground_line_count):
    p.hideturtle()
    p.speed(500)
    for i in range(ground_line_count):
        p.pensize(random.randint(5, 10))
        x = random.randint(-400, 350)
        y = random.randint(-280, -1)
        r = -y / 280
        g = -y / 280
        b = -y / 280
        p.pencolor(r, g, b)
        p.penup()  # 抬起画笔
        p.goto(x, y)  # 让画笔移动到此位置
        p.pendown()  # 放下画笔
        p.forward(random.randint(40, 100))  # 眼当前画笔方向向前移动40~100距离

def main():
    p.setup(800, 600, 0, 0)  #设置显示窗口大小，和画笔初始位置
    # p.tracer(False)
    p.bgcolor("black")
    # p.tracer(False)     #设置动画开关，可以用来加速绘画，不显示过程。默认为ture显示过程
    snow(30)
    ground(20)
    p.mainloop()  #画图执行的命令或者p.done()

main()
