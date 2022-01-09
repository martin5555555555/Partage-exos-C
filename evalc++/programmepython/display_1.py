import itertools
from re import X
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
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
for i in range (n):
    plt.plot(x, results_explicit[:,i],color = cm.hot((n-i)/15))
plt.xlabel('X')
plt.ylabel('Température')
plt.savefig("results_euler_explicit")
plt.close()

for i in range (n):
    plt.plot(x, results_implicit[:,i], color = cm.hot((n-i)/15))
plt.xlabel('X')
plt.ylabel('Température')
plt.savefig("results_euler_implicit")
plt.close()

for i in range (n):
    plt.plot(x, results_explicit_creuse[:,i], color = cm.hot((n-i)/15))
plt.xlabel('X')
plt.ylabel('Température')
plt.savefig("results_euler_explicit_creuse")
plt.close()

for i in range (n):
    plt.plot(x, results_implicit_creuse[:,i], color = cm.hot((n-i)/15))
plt.xlabel('X')
plt.ylabel('Température')
plt.savefig("results_euler_implicit_creuse")
plt.close()

for i in range (n):
    plt.plot(x, results_explicit_D_variable[:,i], color = cm.hot((n-i)/15))
plt.xlabel('X')
plt.ylabel('Température')
plt.savefig("results_euler_explicit_D_variable")
plt.close()



