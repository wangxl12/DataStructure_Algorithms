import os 
from rose import rose_data
import turtle

PATH = os.getcwd() + '/rose_data.txt'
path = os.getcwd() + '/data.txt'

def init_data(PATH):
    """get the initial rose data

    Args:
        PATH ([str]): [the rose data path]
    """
    with open(PATH, "a") as f:
        for value in rose_data.values():
            value = [list(item) for item in value]
            f.write(str(value) + '\n')
            
def change_data(PATH, x=0, y=0):
    with open(PATH, 'r') as f:
        b = f.readlines()
    b = list(map(lambda x: eval(x.strip()), b))
    # (-311, -20) (42, -22)
    # TODO +234.5,  +41
    for lyst in b:
        for item in lyst:
            item[0] += x
            item[1] += y
    with open(PATH.split('/')[0] + '/data.txt', "w") as f:
        for lyst in b:
            f.write(str(lyst) + '\n')
            
def draw_line(pix_list):
    '''依据pix_list的像素点数据画图'''
    turtle.penup()
    turtle.goto(*pix_list[0])
    turtle.pendown()
    for pix in pix_list:
        turtle.goto(*pix)
    
def draw_pic_fill_color(pic_data):
    '''pic_data为字典，每个item储存每一笔的像素点数据'''
    turtle.penup()
    turtle.goto(int(pic_data[0][0][0]), int(pic_data[0][0][1]))
    turtle.pendown()
    for i in range(16):
        turtle.begin_fill()
        turtle.fillcolor('red')
        pix_list = pic_data[i]
        draw_line(pix_list)
        turtle.end_fill()
    
    

def draw_pic(pic_data):
    '''pic_data为字典，每个item储存每一笔的像素点数据'''
    turtle.color("green")
    turtle.pensize(2)
    # TODO 重新描绘花
    for i in range(16):
        pix_list = pic_data[i]
        draw_line(pix_list)
    turtle.pensize(30)
    
    # 枝
    turtle.speed(5)
    pix_list = pic_data[16]
    draw_line(pix_list)
    
    # 叶
    turtle.speed(5)
    
    turtle.pensize(10)
    turtle.penup()
    # ! goto
    # turtle.goto(403, -105)
    turtle.goto(443, -205)
    # turtle.goto(483, -255)
    turtle.pendown()
    
    turtle.left(60)
    turtle.begin_fill()
    turtle.fillcolor('green')
    turtle.circle(-80, 100)
    turtle.right(90)
    turtle.fd(10)
    turtle.left(20)
    turtle.circle(-63, 127)
    turtle.end_fill()
    turtle.penup()
    turtle.left(50)
    turtle.fd(20)
    turtle.left(180)
    turtle.pendown()
    turtle.circle(200, 25)
    
    turtle.penup()
    turtle.right(150)
    turtle.fd(180)
    turtle.right(40)
    # ! goto
    # turtle.goto(345, -140)
    turtle.goto(355, -165)
    turtle.pendown()
    turtle.begin_fill()
    turtle.fillcolor('green')
    turtle.circle(-100, 80)
    turtle.right(150)
    turtle.fd(10)
    turtle.left(60)
    turtle.circle(-80, 98)
    turtle.end_fill()
    turtle.penup()
    turtle.left(60)
    turtle.fd(13)
    turtle.left(180)
    turtle.pendown()
    turtle.speed(5)
    turtle.circle(-200, 23)
    
    # 左边叶子茎
    turtle.pensize(2)
    turtle.color('black')
    turtle.speed(5)
    for i in range(17, 23):
        pix_list = pic_data[i]
        draw_line(pix_list)
    
    # 右边叶子茎
    for i in range(23, 30):
        pix_list = pic_data[i]
        draw_line(pix_list)
        
def init():
    turtle.setup(width=800, height=500, startx=0, starty=0)
    turtle.title('rose')
    turtle.pensize(2)
    turtle.color('green','green')
    
def read_data():
    data = None
    with open(path, 'r') as f:
        data = f.readlines()
        data = [eval(lyst) for lyst in data]
    result = dict(zip(range(len(data)), data))
    return result

def main():
    rose_data = read_data()
    # init()
    draw_pic_fill_color(rose_data)
    draw_pic(rose_data)
    turtle.mainloop()
    
if __name__ == '__main__':
    # init_data(PATH)
    change_data(path, -10, 10)
    # rose_data = read_data()
    # init()
    # draw_pic_fill_color(rose_data)
    # draw_pic(rose_data)
    # turtle.mainloop()