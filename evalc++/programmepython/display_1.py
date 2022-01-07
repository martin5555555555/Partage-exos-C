import itertools
import numpy as np
import matplotlib.pyplot as plt
import time
def text_to_vectors(textfile_name):
    fichier = open(textfile_name, 'r')
    content = fichier.readlines()
    n = len(content)
    for i in range (n-1):
        lists = content[i].split(',')
        lists[-1] = lists[-1][0:-1]
        print(lists)
        content[i] = np.vectorize(int)(np.array(lists))
    lists = content[n-1].split(',')
    content[n-1] = np.vectorize(int)(np.array(lists))
    return content

def text_to_time(textfile_name):
    fichier = open(textfile_name, 'r')
    content = fichier.readlines()
    n = len(content)
    for i in range (n-1):
        lists = content[i][0:-1]
        content[i] = int(lists)
    lists = content[n-1]   
    content[n-1] = int(lists)
    return np.array(content)   


x = [1,2,3]
y = [4,5,6]


plt.plot(x,y)
plt.show()
plt.show(block = False)
input('press <ENTER> to continue')


