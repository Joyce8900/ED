from time import time
import random


fim =0
inicial = 0

def array (v,t):
    for i in range (0,t):
        v.append(i)
    return v


def quickSort(v,s,e):
    if (s<e):
        p = partition (v,s,e)
        quickSort (v,s,p-1)
        quickSort(v,p+1,e)


    
def partition (v,s,e):
    k =v[e]
    j = s-1
    auxiliar = 0
    for i in range (s,e):
        if v[1]<= v[i]:
            j+=1
            auxiliar = v[i]
            v[j] =v[i]
            v[i] = auxiliar
        
    auxiliar = v[e]
    v[e] = v [i+1]
    v[i+1]= auxiliar
    return i+1




def medio (v,t):
  for x in range (0,t):
    v.append(random.randint(1,t))
  return v




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
           

def ta():
    for t in range (100,1001,100):
        total = 0 
        for j in range (0,1000):
            v = []
            v = medio(v,t)
            inicial = (time())
            quickSort(v,0,t-1)
            fim = (time())
            total = total + fim-inicial
        media = total/1000
        print (f"{t}        {media:.5f}")


def tb ():
    for t in range (100,1001,100):
        total = 0
        for j in range(0,10000):
            v=[]
            v=array(v,t)
            inicial = (time())
            quickSort(v,0,t-1)
            fim = (time())
            total+= fim-inicial
        media = total/10000
        print (f"{t}           {media:.6f}")
        


#ta()