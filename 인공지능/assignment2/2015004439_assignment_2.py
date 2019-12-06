from konlpy.tag import Okt
import math
import time

now = time.time()
okt = Okt()

pos_count = 0
pos_num = 0
pos_item = {}
neg_num = 0
neg_count=0
neg_item = {}
fp = open('ratings_train.txt','r',encoding='utf8')
line = fp.readlines()

for row in line:
    split1 = row[:-1].split('\t')
    result = okt.morphs(split1[1])
    if split1[2]== '1':
        pos_count += 1
        for item in result:
            if item in pos_item:
                pos_item[item]+=1
                pos_num+=1
            else:
                pos_item[item]=1
                pos_num+=1
    elif split1[2] == '0':
        neg_count += 1
        for item in result:
            if item in neg_item:
                neg_item[item]+=1
                neg_num+=1
            else:
                neg_item[item]=1
                neg_num+=1
fp.close()
print("complete : %0.2f Min"%((time.time()-now)/60))
now = time.time()
##traing 기반  learning
fp = open('ratings_test.txt','r',encoding='utf8')
line = fp.readlines()
dup = set(pos_item)&set(neg_item)
answer =[]
for row in line:
    temp = []
    split1 = row[:-1].split('\t')
    result = okt.morphs(split1[1])
    pos_per = 0
    neg_per = 0
    for item in result:
        if item in pos_item:
            pos_per+=math.log10((pos_item[item]+1)/(pos_num+len(pos_item)+len(neg_item)-len(dup)))
        else:
            pos_per+=math.log10(1/(pos_num+len(pos_item)+len(neg_item)-len(dup)))    
        if item in neg_item:
            neg_per+=math.log10((neg_item[item]+1)/(neg_num+len(pos_item)+len(neg_item)-len(dup)))
        else:
            neg_per+=math.log10(1/(neg_num+len(neg_item)+len(pos_item)-len(dup)))
            
    pos_per += math.log10(float(pos_count)/(pos_count+neg_count))
    neg_per += math.log10(float(neg_count)/(pos_count+neg_count))

    if split1[1] == 'document':
        temp.append(split1[0])
        temp.append(split1[1])
        temp.append('label\n')
    elif pos_per < neg_per:
        temp.append(split1[0])
        temp.append(split1[1])
        temp.append('0\n')
    elif pos_per > neg_per:
        temp.append(split1[0])
        temp.append(split1[1])
        temp.append('1\n')
    elif pos_per == neg_per:
        temp.append(split1[0])
        temp.append(split1[1])
        temp.append('0\n')

    answer.append(temp)
    
fp.close()
print("complete : %0.2f Min"%((time.time()-now)/60))
now = time.time()
f = open("ratings_result.txt",'w',encoding='utf8')
for line in answer:
    f.writelines(line[0]+'\t'+line[1]+'\t'+line[2])
f.close()
