import numpy as np
import glfw
from OpenGL.GLU import *
from OpenGL.GL import *
gCamAng = 0
gComposedM = np.identity(4)
def render(M, camAng):
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glEnable(GL_DEPTH_TEST)
    glLoadIdentity()

    glOrtho(-1,1,-1,1,-1,1)

    gluLookAt(.1*np.sin(camAng),.1,.1*np.cos(camAng),0,0,0,0,1,0)

    glBegin(GL_LINES)
    glColor3ub(255,0,0)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([1.,0.,0.]))
    glColor3ub(0,255,0)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([0.,1.,0.]))
    glColor3ub(0,0,255)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([0.,0.,1.]))
    glEnd()

    glBegin(GL_TRIANGLES)
    glColor3ub(255, 255, 255)
    glVertex3fv((M@np.array([.0,.5,0.,1.]))[:-1])
    glVertex3fv((M@np.array([.0,.0,0.,1.]))[:-1])
    glVertex3fv((M@np.array([.5,.0,0.,1.]))[:-1])
    glEnd()
def key_callback(window,key,scancode,action,mods):
    global gCamAng, gComposedM
    if action == glfw.PRESS or action == glfw.REPEAT:
        if key == glfw.KEY_1:
            gCamAng += np.radians(-10)
        elif key == glfw.KEY_3:
            gCamAng += np.radians(10)
        elif key == glfw.KEY_Q:
            T = np.array([[1.,0.,0.,-0.1],
                         [0.,1.,0.,0.],
                         [0.,0.,1.,0.],
                         [0.,0.,0.,1.]])
            gComposedM = T@gComposedM
        elif key == glfw.KEY_E:
            T = np.array([[1.,0.,0.,0.1],
                         [0.,1.,0.,0.],
                         [0.,0.,1.,0.],
                         [0.,0.,0.,1.]])
            gComposedM = T@gComposedM
        elif key == glfw.KEY_A:
            T = np.array([[np.cos(np.radians(-10)),0.,np.sin(np.radians(-10)),0.],
                         [0.,1.,0.,0.],
                         [-np.sin(np.radians(-10)),0.,np.cos(np.radians(-10)),0.],
                         [0.,0.,0.,1.]])
            gComposedM = gComposedM@T
        elif key == glfw.KEY_D:
            T = np.array([[np.cos(np.radians(10)),0.,np.sin(np.radians(10)),0.],
                         [0.,1.,0.,0.],
                         [-np.sin(np.radians(10)),0.,np.cos(np.radians(10)),0.],
                         [0.,0.,0.,1.]])
            gComposedM = gComposedM@T
        elif key == glfw.KEY_W:
            T = np.array([[1.,0.,0.,0.],
                         [0.,np.cos(np.radians(-10)),-np.sin(np.radians(-10)),0.],
                         [0.,np.sin(np.radians(-10)),np.cos(np.radians(-10)),0.],
                         [0.,0.,0.,1.]])
            gComposedM = gComposedM@T
        elif key == glfw.KEY_S:
            T = np.array([[1.,0.,0.,0.],
                         [0.,np.cos(np.radians(10)),-np.sin(np.radians(10)),0.],
                         [0.,np.sin(np.radians(10)),np.cos(np.radians(10)),0.],
                         [0.,0.,0.,1.]])
            gComposedM = gComposedM@T
def main():
    global gComposedM, gCamAng
    if not glfw.init():
        return
    window = glfw.create_window(480,480,"2015004439-4-2",None,None)
    if not window:
        glfw.terminate()
        return

    glfw.set_key_callback(window, key_callback)
    glfw.make_context_current(window)

    while not glfw.window_should_close(window):
        glfw.poll_events()
        render(gComposedM, gCamAng)
        glfw.swap_buffers(window)

    glfw.terminate()
if __name__ == "__main__":
    main()
    
