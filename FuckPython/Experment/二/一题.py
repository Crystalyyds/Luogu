 
def fun3(str):
    cnt = 0
    for i in str:
        i = int(i)
        cnt += i
    return cnt

op = input("空格间隔，回车结尾=")
str = op.split(' ')
res = fun3(str)
print(res)