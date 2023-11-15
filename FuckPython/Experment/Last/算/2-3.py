def fun(x):
    if x==0 or x==1:
        return 1
    else :
        return fun(x-1)+fun(x-2);
a=[]
for i in range (0,10):
    a.append(fun(i))
    
print(a)