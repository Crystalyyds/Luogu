import math

op = 0
list=[]
def fun(i):
    for j in range(2,int(math.sqrt(i)+1)):
        if i%j==0 :
            return False
    return True 
for i in  range(2,100):
    if fun(i):
        print("{} ".format(i),end="")
        op+=1
        if op%5==0 :
            print("\n")