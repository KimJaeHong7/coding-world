import numpy as np
import glfw
from OpenGL.GL import *

def render(M):
    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()
    #draw coordinate
    glBegin(GL_LINES)
    glColor3ub(255,0,0)
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([1.,0.]))
    glColor3ub(0,255,0)
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([0.,1.]))
    glEnd()
    glColor3ub(255,255,255)
    p=np.array([0.5,0.,1.])
    v=np.array([0.5,0.,0.])
    glBegin(GL_POINTS)
    glVertex2fv((M@(p+v))[:-1])
    glEnd()
    glBegin(GL_LINES)
    glVertex2fv((M@v)[:-1])
    glVertex2fv((M@np.array([0.,0.,0.]))[:-1])
    glEnd()
def main():
    if not glfw.init():
        return
    window = glfw.create_window(480,480,"2015004439-5-1",None,None)
    if not window:
        glfw.terminate()
        return
    glfw.make_context_current(window)
    glfw.swap_interval(1)

    while not glfw.window_should_close(window):
        glfw.poll_events()
        t=glfw.get_time()
        T=np.array([[np.cos(t),-np.sin(t),0],
                    [np.sin(t),np.cos(t),0],
                    [0,0,1]])
   
        render(T)
        glfw.swap_buffers(window)

    glfw.terminate()
if __name__ == "__main__":
    main()
    
