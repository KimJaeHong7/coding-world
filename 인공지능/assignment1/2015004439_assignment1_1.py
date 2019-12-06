def bfs(r, c, finish, start):
    global time, length, maze, path, check, answer
    i = 0
    j = 0
    for z in range(int(m)): #check 배열 초기화
        for e in range(int(n)):
            check[z][e] = 0
    for z in range(int(m)): #path 배열 초기화
        for e in range(int(n)):
            path[z][e] = 0
    queue =[] #queue 초기화
    queue.append((r,c)) 
    j +=1
    while i < j:#1이면 왼쪽  2이면 오른쪽  3이면 아래쪽 4이면 위쪽
        time += 1
        x = queue[i][0] #pop
        y = queue[i][1]
        check[x][y] = 1
        i += 1
        if(x+1 < int(m) and check[x+1][y] == 0 and maze[x+1][y] == 2):
            queue.append((x+1,y))
            path[x+1][y]=1
            j += 1
        if(x-1 >= 0 and check[x-1][y] == 0 and maze[x-1][y] == 2):
            queue.append((x-1,y))
            path[x-1][y]=2
            j += 1
        if(y+1 < int(n) and check[x][y+1] == 0 and maze[x][y+1] == 2):
            queue.append((x,y+1))
            path[x][y+1]=3
            j += 1       
        if(y-1 >=0 and check[x][y-1] == 0 and maze[x][y-1] == 2):
            queue.append((x,y-1))
            path[x][y-1]=4
            j += 1
        if(maze[x+1][y] == finish):
            path[x+1][y] = 1
            ax = x+1
            ay = y
            break
        if(maze[x-1][y] == finish):
            path[x-1][y] = 2
            ax = x-1
            ay = y
            break
        if(maze[x][y+1] == finish):
            path[x][y+1] = 3
            ax = x
            ay = y+1
            break
        if(maze[x][y-1] == finish):
            path[x][y-1] = 4
            ax = x
            ay = y-1
            break
    temp = ax
    temp1 = ay
    while maze[ax][ay] != start:
        if path[ax][ay] == 4:
            answer[ax][ay+1] = 5
            ay += 1
            length += 1
        elif path[ax][ay] == 3:
            answer[ax][ay-1] = 5
            ay -= 1
            length += 1
        elif path[ax][ay] == 2:
            answer[ax+1][ay] = 5
            ax += 1
            length += 1
        elif path[ax][ay] == 1:
            answer[ax-1][ay] = 5
            ax -= 1
            length += 1
    if start == 3:
        answer[ax][ay] = 3
    return (temp, temp1) 
#########################BFS##################################

#########################IDS##################################
def ids(r, c, start, finish):
    global time, length, maze, path, check, answer
    depth = 0
    flag = 0
    limit = 0
    i = 0
    j = 1
    k = 0
    for z in range(int(m)): #check 배열 초기화
        for e in range(int(n)):
            check[z][e] = 0
    for z in range(int(m)): #path 배열 초기화
        for e in range(int(n)):
            path[z][e] = 0
    while 1:
        stack = []
        for z in range(int(m)): #check 배열 초기화
            for e in range(int(n)):
                check[z][e] = 0
        flag = 0
        stack.append((r,c,depth))
        j = len(stack)
        while j != 0:
            x = stack[j-1][0]
            y = stack[j-1][1]
            z = stack[j-1][2]
            check[x][y] = 1
            del stack[j-1]
            time += 1
            j -= 1
            check[x][y] = 1
            if z < limit:
                if(x+1 < int(m) and check[x+1][y] == 0 and maze[x+1][y] == 2):
                    stack.append((x+1,y, z+1))
                    path[x+1][y]=1
                    j += 1
                if(x-1 >= 0 and check[x-1][y] == 0 and maze[x-1][y] == 2):
                    stack.append((x-1,y,z+1))
                    path[x-1][y]=2
                    j += 1
                if(y+1 < int(n) and check[x][y+1] == 0 and maze[x][y+1] == 2):
                    stack.append((x,y+1, z+1))
                    path[x][y+1]=3
                    j += 1      
                if(y-1 >=0 and check[x][y-1] == 0 and maze[x][y-1] == 2):
                    stack.append((x,y-1,z+1))
                    path[x][y-1]=4
                    j += 1
                if(maze[x+1][y] == finish):
                    path[x+1][y] = 1
                    ax = x+1
                    ay = y
                    flag = 1
                    break
                if(maze[x-1][y] == finish):
                    path[x-1][y] = 2
                    ax = x-1
                    ay = y
                    flag = 1
                    break
                if(maze[x][y+1] == finish):
                    path[x][y+1] = 3
                    ax = x
                    ay = y+1
                    flag = 1
                    break
                if(maze[x][y-1] == finish):
                    path[x][y-1] = 4
                    ax = x
                    ay = y-1
                    flag = 1
                    break
        limit += 1
        if flag == 1:
            break
    temp = ax
    temp1 = ay
    while maze[ax][ay] != start:
        if path[ax][ay] == 4:
            answer[ax][ay+1] = 5
            ay += 1
            length += 1
        elif path[ax][ay] == 3:
            answer[ax][ay-1] = 5
            ay -= 1
            length += 1
        elif path[ax][ay] == 2:
            answer[ax+1][ay] = 5
            ax += 1
            length += 1
        elif path[ax][ay] == 1:
            answer[ax-1][ay] = 5
            ax -= 1
            length += 1
    if start == 3:
        answer[ax][ay] = 3
    return (temp, temp1)
#################################IDS#############################

#########################GBFS############################
def dist(x, y, x1, y1):
    return abs(x-x1) + abs(y-y1)

###heap
class MinHeap():

    def __init__(self):
        self.queue = []

    def swap(self,i,parent_index):
        self.queue[i], self.queue[parent_index] = self.queue[parent_index], self.queue[i]

    def insert(self, x, y, d):
        self.queue.append((x,y,d))
        last_index = len(self.queue)-1

        while 0 <= last_index:
            parent_index = self.parent(last_index)
            if 0 <= parent_index and self.queue[parent_index][2] > self.queue[last_index][2]:
                self.swap(last_index, parent_index)
                last_index = parent_index
            else:
                break

    def minHeapify(self, i):
        left_index = self.leftchild(i)
        right_index = self.rightchild(i)
        min_index = i

        if left_index <= len(self.queue) -1 and self.queue[min_index][2] > self.queue[left_index][2]:
            min_index = left_index
        if right_index <= len(self.queue) -1 and self.queue[min_index][2] > self.queue[right_index][2]:
            min_index = right_index

        if min_index != i:
            self.swap(i, min_index)
            self.minHeapify(min_index)

    def delete(self):
        last_index = len(self.queue) -1
        if last_index < 0:
            return -1
        self.swap(0, last_index)
        del self.queue[last_index]
        self.minHeapify(0)


    def parent(self, index):
        return (index-1) // 2
    
    def leftchild(self, index):
        return index*2 + 1

    def rightchild(self, index):
        return index*2 + 2
###########################heap######################

def a_star(r,c,start,finish, x1, y1):
    global time, length, maze, path, check, answer
    for z in range(int(m)): #check 배열 초기화
        for e in range(int(n)):
            check[z][e] = 0
    for z in range(int(m)): #path 배열 초기화
        for e in range(int(n)):
            path[z][e] = 0
    mh = MinHeap()
    mh.insert(r,c,dist(r,c,x1,y1))
    while len(mh.queue) > 0:
        time += 1
        x = mh.queue[0][0] #pop
        y = mh.queue[0][1]
        z = mh.queue[0][2]
        di = dist(x,y,x1,y1)
        z = z-di
        mh.delete()
        check[x][y] = 1
        if(x+1 < int(m) and check[x+1][y] == 0 and maze[x+1][y] == 2):
            mh.insert(x+1,y,dist(x+1,y,x1,y1)+z+dist(x+1,y,x,y))
            path[x+1][y]=1
        if(x-1 >= 0 and check[x-1][y] == 0 and maze[x-1][y] == 2):
            mh.insert(x-1,y,dist(x-1,y,x1,y1)+z+dist(x-1,y,x,y))
            path[x-1][y]=2
        if(y+1 < int(n) and check[x][y+1] == 0 and maze[x][y+1] == 2):
            mh.insert(x,y+1,dist(x,y+1,x1,y1)+z+dist(x,y+1,x,y))
            path[x][y+1]=3
        if(y-1 >=0 and check[x][y-1] == 0 and maze[x][y-1] == 2):
            mh.insert(x,y-1,dist(x,y-1,x1,y1)+z+dist(x,y-1,x,y))
            path[x][y-1]=4
        if(maze[x+1][y] == finish):
            path[x+1][y] = 1
            ax = x+1
            ay = y
            break
        if(maze[x-1][y] == finish):
            path[x-1][y] = 2
            ax = x-1
            ay = y
            break
        if(maze[x][y+1] == finish):
            path[x][y+1] = 3
            ax = x
            ay = y+1
            break
        if(maze[x][y-1] == finish):
            path[x][y-1] = 4
            ax = x
            ay = y-1
            break
    temp = ax
    temp1 = ay
    while maze[ax][ay] != start:
        if path[ax][ay] == 4:
            answer[ax][ay+1] = 5
            ay += 1
            length += 1
        elif path[ax][ay] == 3:
            answer[ax][ay-1] = 5
            ay -= 1
            length += 1
        elif path[ax][ay] == 2:
            answer[ax+1][ay] = 5
            ax += 1
            length += 1
        elif path[ax][ay] == 1:
            answer[ax-1][ay] = 5
            ax -= 1
            length += 1
    if start == 3:
        answer[ax][ay] = 3
    return (temp, temp1)
#####################a*####################

####################GBFS##########################3
def greedy_bfs(r,c,start,finish, x1, y1):
    global time, length, maze, path, check, answer
    l = 0
    for z in range(int(m)): #check 배열 초기화
        for e in range(int(n)):
            check[z][e] = 0
    for z in range(int(m)): #path 배열 초기화
        for e in range(int(n)):
            path[z][e] = 0
    mh = MinHeap()
    mh.insert(r,c,dist(r,c,x1,y1)+l)
    while len(mh.queue) > 0:
        time += 1
        x = mh.queue[0][0] #pop
        y = mh.queue[0][1]
        mh.delete()
        check[x][y] = 1
        if(x+1 < int(m) and check[x+1][y] == 0 and maze[x+1][y] == 2):
            mh.insert(x+1,y,dist(x+1,y,x1,y1))
            path[x+1][y]=1
        if(x-1 >= 0 and check[x-1][y] == 0 and maze[x-1][y] == 2):
            mh.insert(x-1,y,dist(x-1,y,x1,y1))
            path[x-1][y]=2
        if(y+1 < int(n) and check[x][y+1] == 0 and maze[x][y+1] == 2):
            mh.insert(x,y+1,dist(x,y+1,x1,y1))
            path[x][y+1]=3
        if(y-1 >=0 and check[x][y-1] == 0 and maze[x][y-1] == 2):
            mh.insert(x,y-1,dist(x,y-1,x1,y1))
            path[x][y-1]=4
        if(maze[x+1][y] == finish):
            path[x+1][y] = 1
            ax = x+1
            ay = y
            break
        if(maze[x-1][y] == finish):
            path[x-1][y] = 2
            ax = x-1
            ay = y
            break
        if(maze[x][y+1] == finish):
            path[x][y+1] = 3
            ax = x
            ay = y+1
            break
        if(maze[x][y-1] == finish):
            path[x][y-1] = 4
            ax = x
            ay = y-1
            break
    temp = ax
    temp1 = ay
    while maze[ax][ay] != start:
        if path[ax][ay] == 4:
            answer[ax][ay+1] = 5
            ay += 1
            length += 1
        elif path[ax][ay] == 3:
            answer[ax][ay-1] = 5
            ay -= 1
            length += 1
        elif path[ax][ay] == 2:
            answer[ax+1][ay] = 5
            ax += 1
            length += 1
        elif path[ax][ay] == 1:
            answer[ax-1][ay] = 5
            ax -= 1
            length += 1
    if start == 3:
        answer[ax][ay] = 3
    return (temp, temp1)
###########################maze write###########################
def maze_write(k,m,n,arr):
    global time, num,length, maze, path, check, answer
    length = 0
    time = 0
    i = 0
    maze = [[0 for r in range(int(m))] for c in range(int(n))]
    answer = [[0 for r in range(int(m))] for c in range(int(n))] #초기화
    path = [[0 for r in range(int(m))] for c in range(int(n))] #초기화
    check = [[0 for r in range(int(m))] for c in range(int(n))] #초기화

    for a in arr:
        j = 0
        for b in a:
            if b != '\n':
                maze[i][j] = int(b)
                answer[i][j] = int(b)
            j += 1
        i += 1
        
    o = -1
    u = -1
    for l in range(int(m)):
        for g in range(int(n)):
            if maze[l][g] == 3:
                o = l
                u = g
                break
    q = bfs(o,u,6, 3)
    v = bfs(q[0],q[1],4, 6)
    f = open("Maze_%d_BFS_output.txt"%int(k),"w")
    for l in range(int(m)):
        for g in range(int(n)):
            f.write(str(answer[l][g]))
        f.write('\n')
    f.write("---\n")
    f.write("length=%d\n"%length)
    f.write("time=%d\n"%time)
    f.close()
    
    time = 0
    length = 0
    q = ids(o,u,3, 6)
    v = ids(q[0],q[1],6, 4)
    f = open("Maze_%d_IDS_output.txt"%int(k),"w")
    for l in range(int(m)):
        for g in range(int(n)):
            f.write(str(answer[l][g]))
        f.write('\n')
    f.write("---\n")
    f.write("length=%d\n"%length)
    f.write("time=%d\n"%time)
    f.close()
    
    time = 0
    length = 0
    t = -1
    h = -1
    for l in range(int(m)):
        for g in range(int(n)):
            if maze[l][g] == 6:
                t = l
                h = g
                break
    q = greedy_bfs(o,u,3, 6, t, h)
    for l in range(int(m)):
        for g in range(int(n)):
            if maze[l][g] == 4:
                t = l
                h = g
                break
    v = greedy_bfs(q[0],q[1],6, 4, t, h)
    f = open("Maze_%d_GBFS_output.txt"%int(k),"w")
    for l in range(int(m)):
        for g in range(int(n)):
            f.write(str(answer[l][g]))
        f.write('\n')
    f.write("---\n")
    f.write("length=%d\n"%length)
    f.write("time=%d\n"%time)
    f.close()
    
    time = 0
    length = 0
    for l in range(int(m)):
        for g in range(int(n)):
            if maze[l][g] == 6:
                t = l
                h = g
                break
    q = a_star(o,u,3, 6, t, h)
    for l in range(int(m)):
        for g in range(int(n)):
            if maze[l][g] == 4:
                t = l
                h = g
                break
    v = a_star(q[0],q[1],6, 4, t, h)
    f = open("Maze_%d_A_star_output.txt"%int(k),"w")
    for l in range(int(m)):
        for g in range(int(n)):
            f.write(str(answer[l][g]))
        f.write('\n')
    f.write("---\n")
    f.write("length=%d\n"%length)
    f.write("time=%d\n"%time)
    f.close()
#######################################################################

###############################file input##############################
for num in range(1,4):
    file = open("Maze_%d.txt"%num,'r')
    k,m,n = file.readline().split()
    arr  = file.readlines()
    file.close()
    maze_write(k,m,n,arr)
