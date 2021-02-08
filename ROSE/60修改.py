from turtle import *
import random
from PIL import Image, ImageTk
import tkinter as tk
from time import sleep
from random import choice, uniform, randint
from math import sin, cos, radians
import time
from win32api import GetSystemMetrics
from test import main
from playsound import playsound
from multiprocessing import Process
import multiprocessing as mp
try:
    mp.set_start_method('spawn')
except:
    pass


class Anniversary(object):
    def __init__(self):
        self.width = GetSystemMetrics(0) * 0.95
        self.height = GetSystemMetrics(1) * 0.9
    
    def create_screen(self):
        """
        create the screen
        """
        
        setup(0.95, 0.9, None, None)
        # setup(self.width, self.height, 0, 0)
        # screensize(self.width, self.height)
    
    def lace_work(self):
        """
        draw the lace eage
        """
        pensize(80)
        pencolor("pink")
        ####花边
        penup()
        goto(-self.width / 2,self.height / 2)
        pendown()
        seth(-40)
        pencolor("pink")
        speed(0)
        for i in range(int(self.width / (160 * sin(40))) + 2):
            circle(40,80)
            circle(-40,80)
        seth(-130)
        for i in range(int(self.height / (160 * sin(40))) + 1):
            circle(40,80)
            circle(-40,80)
        circle(40,80)
        seth(140)
        for i in range(int(self.width / (160 * sin(40))) + 2):
            circle(40,80)
            circle(-40,80)
        seth(50)
        for i in range(int(self.height / (160 * sin(40))) + 1):
            circle(40,80)
            circle(-40,80)
        circle(40,80)

        colormode(255)
        pencolor((86, 220, 35))
        penup()
        goto(-self.width / 2,self.height / 2 - 80)
        pendown()
        seth(0)
        # pencolor("green")
        for _ in range(27):
            penup()
            seth(0)
            fd(50)
            pendown()
            write('☘ ',font=("Arial Rounded" , 20 , "normal"))
            
        for _ in range(13):
            penup()
            seth(-90)
            fd(50)
            pendown()
            write('☘ ',font=("Arial Rounded" , 20 , "normal"))
        
        for _ in range(26):
            penup()
            seth(180)
            fd(50)
            pendown()
            write('☘ ',font=("Arial Rounded" , 20 , "normal"))
        
        for _ in range(12):
            penup()
            seth(90)
            fd(50)
            pendown()
            write('☘ ',font=("Arial Rounded" , 20 , "normal"))
    
    def flower(self):
        """
        draw the flower
        """
        seth(0)
        pensize(2)
        color('green','green')
        main()
    
    def guet(self):
        """
        write GUET
        """
        ##GUET
        speed(2)
        
        pensize(10)
        pencolor("green")
        penup()
        goto(-self.width / 4 + 30, self.height / 4)
        pendown()

        write('2020 G U E T',font=("Arial Rounded" , 70 , "normal"))
        penup()
        seth(180)
        fd(self.width / 20)
        seth(-90)
        fd(self.height / 14)
        pendown()
        colormode(255)
        pencolor((253, 203, 2))
        #✿❃❁❈❉✲☀
        write('❀ ✿ ❃ ❁ ❈ ❉ ✲ ☀ ❀ ❃ ❁ ❈',font=("Arial Rounded" , 30 , "normal"))
        penup()
        seth(180)
        fd(self.width / 10)
        seth(90)
        fd(self.height / 10)
        pendown()
        pencolor('pink')

        write('❤♡                   ♡❤‍',font=("Arial Rounded" , 60 , "normal"))
    
    def sixty(self):
        """
        write 60
        """
        #60
        #
        """***************************6*********************************"""
        speed(10)
        penup()
        goto(-self.width * 1 / 4 + 100, self.height / 18  + 20)
        pendown()
        # 设置颜色模式
        colormode(255)
        pencolor((146, 237, 169))
        pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
        write('★',font=("Arial Rounded" , 30 , "normal"))
        for _ in range(4):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(180)
            fd(50)
            pendown()
            write('★',font=("Arial Rounded" , 30 , "normal"))
        for _ in range(9):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(-90)
            fd(40)
            pendown()
            write('★',font=("Arial Rounded" , 30 , "normal"))
        for _ in range(4):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(0)
            fd(50)
            pendown()
            write('★',font=("Arial Rounded" , 30 , "normal"))

        for _ in range(4):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(90)
            fd(40)
            pendown()
            write('★',font=("Arial Rounded" , 30 , "normal"))

        for _ in range(3):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(180)
            fd(50)
            pendown()
            write('★',font=("Arial Rounded" , 30 , "normal"))

        """***************************0*********************************"""

        penup()
        goto(-self.width * 1 / 4 + 280, self.height / 18 + 20)
        pendown()
        write('★',font=("Arial Rounded" , 30 , "normal"))
        for _ in range(9):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(-90)
            fd(40)
            pendown()
            write('★',font=("Arial Rounded" , 30 , "normal"))

        for _ in range(4):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(0)
            fd(50)
            pendown()
            write('★',font=("Arial Rounded" , 30 , "normal"))
        
        for _ in range(9):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(90)
            fd(40)
            pendown()
            write('★',font=("Arial Rounded" , 30 , "normal"))

        for _ in range(4):
            pencolor((randint(0, 255), randint(0, 255), randint(0, 255)))
            penup()
            seth(180)
            fd(50)
            pendown()
            # ⭐
            write('★',font=("Arial Rounded" , 30 , "normal"))

        # penup()
        # seth(180)
        # fd(50)
        # pendown()
        # write('☘',font=("Arial Rounded" , 30 , "normal"))

    def main(self):
        # self.root.after(100, self.simulate, self.cv)
        # image =Image.open("d:/desktop/hua1.jpg")
        # background_image = ImageTk.PhotoImage(image)
        # label = tk.Label(self.root, image=background_image)
        # label.pack()
        self.create_screen()
        self.lace_work()
        self.guet()
        self.sixty()
        self.flower()
        # self.root.mainloop()
        done()

def process1():
    anniversary = Anniversary()
    with anniversary.main() as p1:
        p1.run()

def process2(music_path):
    try:
        with playsound(music_path) as p2:
            p2.run()
    except:
        return 
        

if __name__=="__main__":
    music_path = 'output.mp3'
    processes = [process1, process2]
    jobs = []
    for i in range(len(processes)):
        if i == 0:
            p = Process(target=processes[i])
            jobs.append(p)
            p.start()
        else:
            p = Process(target=processes[i], args=(music_path, ))
            jobs.append(p)
            p.start()
            
    for job in jobs:
        job.join()




 



