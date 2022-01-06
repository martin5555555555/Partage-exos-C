import itertools
import numpy as np

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
        print("burbe")
        lists = content[i][0:-1]
        content[i] = int(lists)
    lists = content[n-1]   
    content[n-1] = int(lists)
    return np.array(content)   

text_to_time("time_euler_explicit")

