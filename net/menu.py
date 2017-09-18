from graphics import *

def main():
    width = 860
    height = 420
    win = GraphWin("My Circle", width, height)
    c = Circle(Point(width/2, height/2), 50)
    c.draw(win)
    win.getMouse()
    c.undraw()
    d = Circle(Point(60, 100), 50)
    d.draw(win)
    win.getMouse()
    win.close()
main()
