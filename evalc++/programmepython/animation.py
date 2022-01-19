import itertools
from re import X
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import matplotlib.animation as animation


#plt.use('Agg') # no UI backend

import time
def text_to_vectors(textfile_name):
    fichier = open(textfile_name, 'r')
    content = fichier.readlines()
    n = len(content)
    m = len(content[0].split(','))-1
    res = np.zeros((m,n))

    for i in range (n):
        lists = content[i].split(',')
        lists =lists[0:-1]
        res[:,i] = np.vectorize(float)(np.array(lists))
    return res

def text_to_time(textfile_name):
    fichier = open(textfile_name, 'r')
    content = fichier.readlines()
    n = len(content)
    for i in range (n-1):
        lists = content[i][0:-1]
        content[i] = float(lists)
    lists = content[n-1]   
    content[n-1] = float(lists)
    return np.array(content)   


time = text_to_time("../../programmepython/time_euler_explicit")

results_explicit = text_to_vectors("../../programmepython/results_euler_explicit") 
results_implicit = text_to_vectors("../../programmepython/results_euler_implicit") 
results_explicit_creuse = text_to_vectors("../../programmepython/results_euler_explicit_creuse") 
results_implicit_creuse = text_to_vectors("../../programmepython/results_euler_implicit_creuse") 
results_explicit_D_variable = text_to_vectors("../../programmepython/results_euler_explicit_D_variable") 


delta_x = 0.1
x = np.arange(0,1,delta_x)
n = len(results_explicit)

fig = plt.figure() # initialise la figure
line, = plt.plot([], [])

def animate(i):
    x = np.arange(0, len(results_explicit[:,i]), 1)
    y =  results_explicit[:,i]
    line.set_data(x, y)
    return line
# Set up formatting for the movie files
Writer = animation.writers['ffmpeg']
writer = Writer(fps=15, metadata=dict(artist='Me'), bitrate=1800)

ani = animation.FuncAnimation(fig, animate, frames=len(time), interval=2)
ani.save("../../animation.mp4", writer = writer)
