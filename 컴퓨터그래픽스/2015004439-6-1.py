import numpy as np
import glfw
from OpenGL.GLU import *
from OpenGL.GL import *
gCamAng = 0.
gCamHeight = 1.
def drawUnitCube():
    glBegin(GL_QUADS)
    glVertex3f( 0.5, 0.5,-0.5)
    glVertex3f(-0.5, 0.5,-0.5)
    glVertex3f(-0.5, 0.5, 0.5)
    glVertex3f( 0.5, 0.5, 0.5)

    glVertex3f( 0.5,-0.5, 0.5)
    glVertex3f(-0.5,-0.5, 0.5)
    glVertex3f(-0.5,-0.5,-0.5)
    glVertex3f( 0.5,-0.5,-0.5)

    glVertex3f( 0.5, 0.5, 0.5)
    glVertex3f(-0.5, 0.5, 0.5)
    glVertex3f(-0.5,-0.5, 0.5)
    glVertex3f( 0.5,-0.5, 0.5)

    glVertex3f( 0.5,-0.5,-0.5)
    glVertex3f(-0.5,-0.5,-0.5)
    glVertex3f(-0.5, 0.5,-0.5)
    glVertex3f( 0.5, 0.5,-0.5)

    glVertex3f(-0.5, 0.5, 0.5)
    glVertex3f(-0.5, 0.5, -0.5)
    glVertex3f(-0.5, -0.5, -0.5)
    glVertex3f(-0.5, -0.5, 0.5)

    glVertex3f(0.5, 0.5, -0.5)
    glVertex3f(0.5, 0.5, 0.5)
    glVertex3f(0.5, -0.5, 0.5)
    glVertex3f(0.5, -0.5, -0.5)
    glEnd()

def drawCubeArray():
    for i in range(5):
        for j in range(5):
            for k in range(5):
                glPushMatrix()
                glTranslatef(i,j,-k-1)
                glScalef(.5,.5,.5)
                drawUnitCube()
                glPopMatrix()

def drawFrame():
    glBegin(GL_LINES)
    glColor3ub(255, 0, 0)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([1.,0.,0.]))
    glColor3ub(0, 255, 0)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([0.,1.,0.]))
    glColor3ub(0, 0, 255)
    glVertex3fv(np.array([0.,0.,0]))
    glVertex3fv(np.array([0.,0.,1.]))
    glEnd()
def render():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glEnable(GL_DEPTH_TEST)
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE)
    glLoadIdentity()

    myOrtho(-5,5,-5,5,-8,8)
    #glOrtho(-5,5,-5,5,-8,8)
    #gluLookAt(5,3,5,1,1,-1,0,1,0)
    myLookAt(np.array([5,3,5]),np.array([1,1,-1]),np.array([0,1,0]))

    drawFrame()

    glColor3ub(255,255,255)
    drawCubeArray()

def myOrtho(left, right, bottom,top,near,far):
    M = np.identity(4)
    M[0,0] = 2/(right-left)
    M[0,3] = -(right+left)/(right-left)
    M[1,1] = 2/(top-bottom)
    M[1,3] = -(top+bottom)/(top-bottom)
    M[2,2] = -2/(far-near)
    M[2,3] = -(far+near)/(far-near)

    glMultMatrixf(M.T)
def myLookAt(eye, at, up):
    M = np.identity(4)
    w = np.array(3)
    w=(eye-at)/np.sqrt(np.dot(eye-at,eye-at))
    u = np.array(3)
    u = np.cross(up,w)/np.sqrt(np.dot(np.cross(up,w),np.cross(up,w)))
    v = np.array(3)
    v = np.cross(w,u)
    M[0,:3] = u
    M[0,3] = -np.dot(u,eye)
    M[1,:3] = v
    M[1,3] = -np.dot(v,eye)
    M[2,:3] = w
    M[2,3] = -np.dot(w,eye)
    glMultMatrixf(M.T)
    
def main():
    global camAng
    if not glfw.init():
        return

    window = glfw.create_window(480,480,"2015004439-6-1", None,None)
    if not window:
        glfw.terminate()
        return

    glfw.make_context_current(window)


    while not glfw.window_should_close(window):
        glfw.poll_events()

        render()
        glfw.swap_buffers(window)
    glfw.terminate()

if __name__ == "__main__":
    main()
