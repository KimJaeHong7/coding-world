import random
def FrozenLake(k,m,n,arr):#0 아래 1 위 2 오른쪽 3 왼쪽
    num_episodes = 20000000
    lake = [[0 for r in range(int(n))] for c in range(int(m))]
    Q = [[0 for r in range(int(n))] for c in range(int(m))]
    i = 0
    j = 0
    for a in arr:
        j = 0
        for b in a:
            if b != '\n':
                lake[i][j] = b
            j += 1
        i += 1
    tmp = int(m)
    tmp1 = int(n)
    for i in range(int(m)):
        for j in range(int(n)):
            if i+1==tmp:
                if j==0:
                    Q[i][j]={}
                    Q[i][j][1]=0
                    Q[i][j][2]=0
                elif j!=0 and j!=tmp1-1:
                    Q[i][j]={}
                    Q[i][j][1]=0
                    Q[i][j][2]=0
                    Q[i][j][3]=0
                elif j==tmp1-1:
                    Q[i][j]={}
                    Q[i][j][1]=0
                    Q[i][j][3]=0
            elif i==0:
                if j==0:
                    Q[i][j]={}
                    Q[i][j][0]=0
                    Q[i][j][2]=0
                elif j!=0 and j!=tmp1-1:
                    Q[i][j]={}
                    Q[i][j][0]=0
                    Q[i][j][2]=0
                    Q[i][j][3]=0
                elif j==tmp1-1:
                    Q[i][j]={}
                    Q[i][j][0]=0
                    Q[i][j][3]=0
            else:
                if j==0:
                    Q[i][j]={}
                    Q[i][j][0]=0
                    Q[i][j][1]=0
                    Q[i][j][2]=0
                elif j!=0 and j!=tmp1-1:
                    Q[i][j]={}
                    Q[i][j][0]=0
                    Q[i][j][1]=0
                    Q[i][j][2]=0
                    Q[i][j][3]=0
                elif j==tmp1-1:
                    Q[i][j]={}
                    Q[i][j][0]=0
                    Q[i][j][1]=0
                    Q[i][j][3]=0
    flag = 0
    cur_x=0
    cur_y=0
    for i in range(int(m)):
        for j in range(int(n)):
            if lake[i][j] == 'S':
                cur_x = i
                cur_y = j
                flag = 1
                break
        if flag == 1:
            break
    start = cur_x
    finish = cur_y
    for i in range(num_episodes):
        done = False
        while not done:
            action = random.randint(0,3)
            while action not in Q[cur_x][cur_y]:
                action = random.randint(0,3)
            if action == 0:
                next_x = cur_x+1
                next_y = cur_y
                state = lake[cur_x+1][cur_y]
            elif action == 1:
                next_x = cur_x-1
                next_y = cur_y
                state = lake[cur_x-1][cur_y]
            elif action == 2:
                next_x = cur_x
                next_y = cur_y+1
                state = lake[cur_x][cur_y+1]
            elif action == 3:
                next_x = cur_x
                next_y = cur_y-1
                state = lake[cur_x][cur_y-1]
            if state == 'H':
                Q[cur_x][cur_y][action] = -1 + 0.5*max(Q[next_x][next_y].values())
                cur_x=start
                cur_y=finish
                done = True
            elif state == 'G':
                Q[cur_x][cur_y][action] = 1+ 0.5*max(Q[next_x][next_y].values())
                cur_x=start
                cur_y=finish
                done = True
            elif state == 'F':
                Q[cur_x][cur_y][action] = 0.5*max(Q[next_x][next_y].values())
                cur_x=next_x
                cur_y=next_y
    new_x=start
    new_y=finish
    while lake[new_x][new_y]!='G':
        if lake[new_x][new_y] != 'S':
            lake[new_x][new_y] = 'R'
        temp = find_key(new_x,new_y,Q)
        if temp == 0:
            new_x = new_x+1
        elif temp == 1:
            new_x = new_x-1
        elif temp == 2:
            new_y = new_y+1
        elif temp == 3:
            new_y = new_y-1
    f = open("FrozenLake_%s_output.txt" %k, "w")
    f.write(k+" "+m+" "+n+"\n")
    for i in range(int(m)):
        for j in range(int(n)):
            f.write(lake[i][j])
        f.write('\n')   
    f.close()
def find_key(new_x,new_y,Q):
    max_value = 0
    max_k=-9999
    for i in range(4):
        if i not in Q[new_x][new_y]:
            continue
        else:
            if max_k < Q[new_x][new_y][i]:
                max_k = Q[new_x][new_y][i]
                max_value = i
    return max_value

for num in range(1,4):
    file = open("FrozenLake_%d.txt"%num,'r')
    k,m,n = file.readline().split()
    arr = file.readlines()
    file.close()
    FrozenLake(k,m,n,arr)


