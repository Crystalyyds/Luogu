a = [2,4,6,12,321]
def fun(x):
    cnt = 0
    for i in x:
        cnt+=i
    return cnt

print("{}".format(fun(a)))
