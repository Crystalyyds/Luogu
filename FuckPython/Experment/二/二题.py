
def fun (n):
    if n==1:
        return 1;
    else:
        return n*fun(n-1)

n = int(input("输入n="))

print("{}的阶乘是={}".format(n,fun(n)))