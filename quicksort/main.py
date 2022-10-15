from time import time
from random import randint
import sys
sys.setrecursionlimit(5000)

# inicio = 0
# fim = 0


def medio(v, t):
    for x in range(0, t):
        v.append(randint(1, t))
    return v


def array(v, t):
    for i in range(0, t):
        v.append(i)
    return v


def quickSort(v, s, e):
    if (s < e):
        p = partition(v, s, e)
        quickSort(v, s, p-1)
        quickSort(v, p+1, e)


def partition(v, s, e):
    #####Descomente para o melhor Caso#####
    # meio = (s+e)//2
    # auxilia = v[meio]
    # v[meio] = v[e]
    # v[e] = auxilia
    ######################################

    k = v[e]
    i = s-1
    auxilia = 0
    for j in range(s, e):
        if v[j] <= k:
            i += 1
            auxilia = v[j]
            v[j] = v[i]
            v[i] = auxilia
    auxilia = v[e]
    v[e] = v[i+1]
    v[i+1] = auxilia
    return i+1


def tb():
    for t in range(100, 1001, 100):
        total = 0
        for j in range(0, 1000):
            v = []
            v = array(v, t)
            inicio = (time())
            quickSort(v, 0, t-1)
            fim = (time())
            total += fim-inicio
        media = total/1000
        print(f"{t}           {media:.6f}")


def ta():
    for t in range(100, 1001, 100):
        total = 0
        for j in range(0, 1000):
            v = []
            v = medio(v, t)
            inicio = (time())
            quickSort(v, 0, t-1)
            fim = (time())
            total = total + fim-inicio
        media = total/1000
        print(f"{t}        {media:.5f}")

def tw ():
    for t in range (100,1001,100):
        total = 0 
        for j in range (0,1000):
            v = []
            v = array(v,t)
            inicial = (time())
            quickSort(v,0,t-1)
            fim = (time())
            total = total + fim-inicial
        media = total/1000
        print (f"{t}     {media:.5f}")
           
