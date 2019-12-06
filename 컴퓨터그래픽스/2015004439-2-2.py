import numpy as np
import glfw
from OpenGL.GL import *
kind=GL_LINE_LOOP
def render():
    global kind
    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()
    glBegin(kind)
    a=np.linspace(0,2*np.pi,13)
    for i in range(12):
        glVertex2f(np.cos(a[i]),np.sin(a[i]))
    glEnd()
def key_callback(window,key,scancode,action,mods):
    global kind
    if key==glfw.KEY_1 and action == glfw.PRESS:
        kind = GL_POINTS
    elif key==glfw.KEY_2 and action == glfw.PRESS:
        kind = GL_LINES
    elif key==glfw.KEY_3 and action == glfw.PRESS:
        kind = GL_LINE_STRIP
    elif key==glfw.KEY_4 and action == glfw.PRESS:
        kind = GL_LINE_LOOP
    elif key==glfw.KEY_5 and action == glfw.PRESS:
        kind = GL_TRIANGLES
    elif key==glfw.KEY_6 and action == glfw.PRESS:
        kind = GL_TRIANGLE_STRIP
    elif key==glfw.KEY_7 and action == glfw.PRESS:
        kind = GL_TRIANGLE_FAN
    elif key==glfw.KEY_8 and action == glfw.PRESS:
        kind = GL_QUADS
    elif key==glfw.KEY_9 and action == glfw.PRESS:
        kind = GL_QUAD_STRIP
    elif key==glfw.KEY_0 and action == glfw.PRESS:
        kind = GL_POLYGON
def main():
    if not glfw.init():
        return
    window = glfw.create_window(480,480,"2015004439-2-2",None,None)
    if not window:
        glfw.terminate()
        return

    glfw.set_key_callback(window, key_callback)
    glfw.make_context_current(window)

    while not glfw.window_should_close(window):
        glfw.poll_events()
        render()
        glfw.swap_buffers(window)

    glfw.terminate()
if __name__ == "__main__":
    main()
    
